#define _USE_MATH_DEFINES
#define UNIFORM "Uniform"
#define CHORDAL "Chordal"
#define CENTRIPETAL "Centripetal"
#define FOLEY "Foley"
#define BEZIER "Bezier"

#include "CanvasSystem.h"
#include "../Components/CanvasData.h"

#include <_deps/imgui/imgui.h>
#include <cstring>
#include <math.h>
#include <numeric>
#include <spdlog/spdlog.h>
#include <Eigen/Sparse>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
using namespace Ubpa;

float CalDistance(pointf2 pos1, pointf2 pos2);
vector<float> Parameterization(vector<pointf2> data_points, string parameterization_type);
vector<pointf2> DrawCubicParametricSpline(vector<float> t, vector<pointf2> data_points, float sampling_period = 0.001f);
vector<pointf2> InitBezierCurveCtrlPoints(vector<pointf2> data_points);
vector<pointf2> DrawCubicBezierCurve(vector<pointf2> data_ctrl_points, float sampling_period = 0.005f);
void DrawCurve(ImDrawList* draw_list, float origin_x, float origin_y, vector<pointf2> draw_points, string parameterization_type);

void CanvasSystem::OnUpdate(Ubpa::UECS::Schedule& schedule) {
	schedule.RegisterCommand([](Ubpa::UECS::World* w) {
		auto data = w->entityMngr.GetSingleton<CanvasData>();
		if (!data)
			return;

		if (ImGui::Begin("Canvas")) {
			ImGui::Checkbox("Enable grid", &data->opt_enable_grid);
			ImGui::Checkbox("Enable context menu", &data->opt_enable_context_menu);
			//ImGui::Text("Mouse Left: drag to add lines,\nMouse Right: drag to scroll, click for context menu.");
			ImGui::Separator();
			ImGui::RadioButton("Draw Cubic Spline\t", &data->btn_radio1, 0); ImGui::SameLine();
			ImGui::RadioButton("Edit Cubic Spline\t", &data->btn_radio1, 1);

			if (data->btn_radio1 == 0 || data->btn_radio1 == 1) {
				ImGui::SameLine();
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 165, 0, 255));
				ImGui::Checkbox("Uniform", &data->opt_equidistant);
				ImGui::PopStyleColor();

				ImGui::SameLine();
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(255, 255, 0, 255));
				ImGui::Checkbox("Chordal", &data->opt_chordal);
				ImGui::PopStyleColor();

				ImGui::SameLine();
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 0, 255));
				ImGui::Checkbox("Centripetal", &data->opt_centripetal);
				ImGui::PopStyleColor();

				ImGui::SameLine();
				ImGui::PushStyleColor(ImGuiCol_Text, IM_COL32(0, 255, 255, 255));
				ImGui::Checkbox("Foley", &data->opt_foley);
				ImGui::PopStyleColor();
			}

			ImGui::RadioButton("Draw Bezier Curve\t", &data->btn_radio1, 2); ImGui::SameLine();
			ImGui::RadioButton("Edit Bezier Curve\t", &data->btn_radio1, 3);
			if (data->btn_radio1 == 3) {
				ImGui::SameLine(); ImGui::RadioButton("C1\t", &data->btn_radio2, 0);
				ImGui::SameLine(); ImGui::RadioButton("G1\t", &data->btn_radio2, 1);
				ImGui::SameLine(); ImGui::RadioButton("C0\t", &data->btn_radio2, 2);
			}

			ImGui::Text("Press [Space] to finish drawing; Press [Z] to print the pos of all type points.");

			// Typically you would use a BeginChild()/EndChild() pair to benefit from a clipping region + own scrolling.
			// Here we demonstrate that this can be replaced by simple offsetting + custom drawing + PushClipRect/PopClipRect() calls.
			// To use a child window instead we could use, e.g:
			//      ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));      // Disable padding
			//      ImGui::PushStyleColor(ImGuiCol_ChildBg, IM_COL32(50, 50, 50, 255));  // Set a background color
			//      ImGui::BeginChild("canvas", ImVec2(0.0f, 0.0f), true, ImGuiWindowFlags_NoMove);
			//      ImGui::PopStyleColor();
			//      ImGui::PopStyleVar();
			//      [...]
			//      ImGui::EndChild();

			// Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use IsItemHovered()/IsItemActive()
			ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
			ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
			if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
			if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
			ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

			// Draw border and background color
			ImGuiIO& io = ImGui::GetIO();
			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
			draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

			// This will catch our interactions
			ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
			const bool is_hovered = ImGui::IsItemHovered(); // Hovered
			const bool is_active = ImGui::IsItemActive();   // Held
			const ImVec2 origin(canvas_p0.x + data->scrolling[0], canvas_p0.y + data->scrolling[1]); // Lock scrolled origin
			const pointf2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

			// Draw Curve
			if (data->btn_radio1 == 0 || data->btn_radio1 == 2) {
				data->editing_points = false;
				data->editing_type_points = false;
				data->editing_ctrl_points = false;

				if (is_hovered && !data->adding_line && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
					data->points.push_back(mouse_pos_in_canvas);
					data->adding_line = true;
				}
				if (data->adding_line) {
					data->points.back() = mouse_pos_in_canvas;
					if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Space))) {
						if (data->points.size() == 2) {
							data->points.clear();
							data->ctrl_points.clear();
						}
						else {
							data->points.resize(data->points.size() - 1);
							if (data->ctrl_points.size() > 2)
								data->ctrl_points.resize(data->ctrl_points.size() - 3);
						}
						data->adding_line = false;
					}
					else if (ImGui::IsMouseClicked(ImGuiMouseButton_Left)) {
						data->points.push_back(mouse_pos_in_canvas);
					}
				}
			}

			// Edit points
			if ((data->btn_radio1 == 1 || data->btn_radio1 == 3) && data->points.size() > 1 && !data->editing_type_points && !data->editing_ctrl_points) {
				vector<pointf2>::iterator iter = data->points.begin();
				while (iter != data->points.end()) {
					if (CalDistance(mouse_pos_in_canvas, *iter) <= 5.0f && ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
						// Get the index of the selected type point
						data->type_point_index = distance(data->points.begin(), iter);

						// Save the pos of the selected type point & its ctrl points for editing Bezier curve
						if (data->ctrl_points.size() > 0) {
							data->selected_type_point = data->points[data->type_point_index];
							if (data->type_point_index > 0)
								data->selected_ctrl_point1 = data->ctrl_points[3 * data->type_point_index - 1];
							if (data->type_point_index < data->points.size() - 1)
								data->selected_ctrl_point2 = data->ctrl_points[3 * data->type_point_index + 1];
						}

						data->editing_points = true;
						data->editing_type_points = true;
						break;
					}
					iter++;
				}

				if (data->btn_radio1 == 3 && data->editing_points && !data->editing_type_points) {
					int index = data->type_point_index;
					if (index > 0 && CalDistance(mouse_pos_in_canvas, data->ctrl_points[3 * index - 1]) <= 5.0f && ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
						// Get the index of the selected ctrl point
						data->ctrl_point_index = 3 * index - 1;
						data->editing_ctrl_points = true;
					}
					if (index < data->points.size() - 1 && CalDistance(mouse_pos_in_canvas, data->ctrl_points[3 * index + 1]) <= 5.0f && ImGui::IsMouseDown(ImGuiMouseButton_Left) && !data->editing_ctrl_points) {
						data->ctrl_point_index = 3 * index + 1;
						data->editing_ctrl_points = true;
					}
				}

				if ((!data->editing_type_points && !data->editing_ctrl_points && ImGui::IsMouseClicked(ImGuiMouseButton_Left)) || ImGui::IsMouseClicked(ImGuiMouseButton_Right))
					data->editing_points = false;
			}

			// Edit type points
			if ((data->btn_radio1 == 1 || data->btn_radio1 == 3) && data->editing_type_points && ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
				data->points[data->type_point_index] = mouse_pos_in_canvas;
				if (data->ctrl_points.size() > 0) {
					data->ctrl_points[3 * data->type_point_index] = mouse_pos_in_canvas;
					if (data->type_point_index > 0) {
						data->ctrl_points[3 * data->type_point_index - 1][0] = data->selected_ctrl_point1[0] + mouse_pos_in_canvas[0] - data->selected_type_point[0];
						data->ctrl_points[3 * data->type_point_index - 1][1] = data->selected_ctrl_point1[1] + mouse_pos_in_canvas[1] - data->selected_type_point[1];
					}
					if (data->type_point_index < data->points.size() - 1) {
						data->ctrl_points[3 * data->type_point_index + 1][0] = data->selected_ctrl_point2[0] + mouse_pos_in_canvas[0] - data->selected_type_point[0];
						data->ctrl_points[3 * data->type_point_index + 1][1] = data->selected_ctrl_point2[1] + mouse_pos_in_canvas[1] - data->selected_type_point[1];
					}
				}
			}

			if ((data->btn_radio1 == 1 || data->btn_radio1 == 3) && data->editing_type_points && ImGui::IsMouseReleased(ImGuiMouseButton_Left)) {
				data->editing_type_points = false;
			}

			// Edit ctrl points
			if (data->btn_radio1 == 3 && data->editing_ctrl_points && ImGui::IsMouseDown(ImGuiMouseButton_Left)) {
				data->ctrl_points[data->ctrl_point_index] = mouse_pos_in_canvas;
				// C1
				if (data->btn_radio2 == 0 && data->type_point_index > 0 && data->type_point_index < data->points.size() - 1) {
					if (data->ctrl_point_index < 3 * data->type_point_index) {
						data->ctrl_points[data->ctrl_point_index + 2][0] = 2.0f * data->points[data->type_point_index][0] - data->ctrl_points[data->ctrl_point_index][0];
						data->ctrl_points[data->ctrl_point_index + 2][1] = 2.0f * data->points[data->type_point_index][1] - data->ctrl_points[data->ctrl_point_index][1];
					}
					else {
						data->ctrl_points[data->ctrl_point_index - 2][0] = 2.0f * data->points[data->type_point_index][0] - data->ctrl_points[data->ctrl_point_index][0];
						data->ctrl_points[data->ctrl_point_index - 2][1] = 2.0f * data->points[data->type_point_index][1] - data->ctrl_points[data->ctrl_point_index][1];
					}
				}
				// G1
				else if (data->btn_radio2 == 1 && data->type_point_index > 0 && data->type_point_index < data->points.size() - 1) {
					float R = CalDistance(data->points[data->type_point_index], mouse_pos_in_canvas);
					if (R != 0.0f && data->ctrl_point_index < 3 * data->type_point_index) {
						float r = CalDistance(data->points[data->type_point_index], data->selected_ctrl_point2);
						data->ctrl_points[data->ctrl_point_index + 2][0] = (1.0f + r / R) * data->points[data->type_point_index][0] - r / R * data->ctrl_points[data->ctrl_point_index][0];
						data->ctrl_points[data->ctrl_point_index + 2][1] = (1.0f + r / R) * data->points[data->type_point_index][1] - r / R * data->ctrl_points[data->ctrl_point_index][1];
						data->selected_ctrl_point1 = data->ctrl_points[data->ctrl_point_index];
						data->selected_ctrl_point2 = data->ctrl_points[data->ctrl_point_index + 2];
					}
					else if (R != 0.0f && data->ctrl_point_index > 3 * data->type_point_index) {
						float r = CalDistance(data->points[data->type_point_index], data->selected_ctrl_point1);
						data->ctrl_points[data->ctrl_point_index - 2][0] = (1.0f + r / R) * data->points[data->type_point_index][0] - r / R * data->ctrl_points[data->ctrl_point_index][0];
						data->ctrl_points[data->ctrl_point_index - 2][1] = (1.0f + r / R) * data->points[data->type_point_index][1] - r / R * data->ctrl_points[data->ctrl_point_index][1];
						data->selected_ctrl_point1 = data->ctrl_points[data->ctrl_point_index - 2];
						data->selected_ctrl_point2 = data->ctrl_points[data->ctrl_point_index];
					}
				}
				// C0无需处理
			}

			if (data->btn_radio1 == 3 && data->editing_ctrl_points && ImGui::IsMouseReleased(ImGuiMouseButton_Left)) {
				data->editing_ctrl_points = false;
			}

			// Pan (we use a zero mouse threshold when there's no context menu)
			// You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
			const float mouse_threshold_for_pan = data->opt_enable_context_menu ? -1.0f : 0.0f;
			if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
			{
				data->scrolling[0] += io.MouseDelta.x;
				data->scrolling[1] += io.MouseDelta.y;
			}

			// Context menu (under default mouse threshold)
			ImVec2 drag_delta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Right);
			if (data->opt_enable_context_menu && ImGui::IsMouseReleased(ImGuiMouseButton_Right) && drag_delta.x == 0.0f && drag_delta.y == 0.0f)
				ImGui::OpenPopupContextItem("context");
			if (ImGui::BeginPopup("context"))
			{
				if (data->adding_line) {
					if (data->points.size() == 2) {
						data->points.clear();
						data->ctrl_points.clear();
					}
					else {
						data->points.resize(data->points.size() - 1);
						if (data->ctrl_points.size() > 2)
							data->ctrl_points.resize(data->ctrl_points.size() - 3);
					}
					data->adding_line = false;
				}

				if (ImGui::MenuItem("Remove one", NULL, false, data->points.size() > 0)) {
					if (data->points.size() == 2) {
						data->points.clear();
						data->ctrl_points.clear();
					}
					else {
						data->points.resize(data->points.size() - 1);
						if (data->ctrl_points.size() > 2)
							data->ctrl_points.resize(data->ctrl_points.size() - 3);
					}
				}
				if (ImGui::MenuItem("Remove all", NULL, false, data->points.size() > 0)) {
					data->points.clear();
					data->ctrl_points.clear();
				}
				ImGui::EndPopup();
			}

			// Print all coordinates
			if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)) && data->points.size() > 0) {
				for (int i = 0; i < data->points.size(); i++) {
					spdlog::info("(" + to_string((int)data->points[i][0]) + ", " + to_string((int)data->points[i][1]) + ")");
				}
			}

			if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_X)) && data->ctrl_points.size() > 0) {
				for (int i = 0; i < data->ctrl_points.size(); i++) {
					spdlog::info("(" + to_string((int)data->ctrl_points[i][0]) + ", " + to_string((int)data->ctrl_points[i][1]) + ")");
				}
			}

			// Draw grid + all lines in the canvas
			draw_list->PushClipRect(canvas_p0, canvas_p1, true);
			if (data->opt_enable_grid)
			{
				const float GRID_STEP = 64.0f;
				for (float x = fmodf(data->scrolling[0], GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
					draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40));
				for (float y = fmodf(data->scrolling[1], GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
					draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40));
			}

			// Draw curve & type points
			if (data->points.size() > 1) {
				// Draw curve
				vector<pointf2> draw_points(data->points);
				if (data->btn_radio1 == 0 || data->btn_radio1 == 1) {
					if (data->opt_equidistant) {
						if (data->points.size() > 2) {
							vector<float> t = Parameterization(data->points, UNIFORM);
							draw_points = DrawCubicParametricSpline(t, data->points);
						}
						DrawCurve(draw_list, origin.x, origin.y, draw_points, UNIFORM);
					}
					// 除Uniform均匀参数化外，其它三种参数化都要求相邻型值点不能重合，否则输出nan/inf或报错，因此拷贝一份型值点集进行处理
					vector<pointf2> data_points(data->points);
					vector<pointf2>::iterator iter = data_points.begin();
					vector<pointf2>::iterator iterEnd = data_points.end();
					while (iter != iterEnd - 1) {
						if ((*iter) == (*(iter + 1))) {
							data_points.erase(iter); // 若当前位置之后存在重复元素，删除当前元素
							break;
						}
						iter++;
					}
					draw_points.assign(data_points.begin(), data_points.end());
					if (data->opt_chordal) {
						if (data_points.size() > 2) {
							vector<float> t = Parameterization(data_points, CHORDAL);
							draw_points = DrawCubicParametricSpline(t, data_points);
						}
						DrawCurve(draw_list, origin.x, origin.y, draw_points, CHORDAL);
					}
					if (data->opt_centripetal) {
						if (data_points.size() > 2) {
							vector<float> t = Parameterization(data_points, CENTRIPETAL);
							draw_points = DrawCubicParametricSpline(t, data_points);
						}
						DrawCurve(draw_list, origin.x, origin.y, draw_points, CENTRIPETAL);
					}
					if (data->opt_foley) {
						if (data_points.size() > 2) {
							vector<float> t = Parameterization(data_points, FOLEY);
							draw_points = DrawCubicParametricSpline(t, data_points);
						}
						DrawCurve(draw_list, origin.x, origin.y, draw_points, FOLEY);
					}
				}
				else if (data->btn_radio1 == 2 || data->btn_radio1 == 3) {
					if (data->btn_radio1 == 2 || data->ctrl_points.size() != data->points.size() * 3 - 2)
						data->ctrl_points = InitBezierCurveCtrlPoints(data->points);
					draw_points = DrawCubicBezierCurve(data->ctrl_points); // ImGui提供了AddBezierCurve()函数
					DrawCurve(draw_list, origin.x, origin.y, draw_points, BEZIER);
				}

				// Draw type points
				for (int n = 0; n < data->points.size() - 1; n++) {
					draw_list->AddCircleFilled(ImVec2(data->points[n][0] + origin.x, data->points[n][1] + origin.y), 4.0f, IM_COL32(255, 0, 0, 255));
				}
				if (!data->adding_line)
					draw_list->AddCircleFilled(ImVec2(data->points[data->points.size() - 1][0] + origin.x, data->points[data->points.size() - 1][1] + origin.y), 4.0f, IM_COL32(255, 0, 0, 255));

				// Draw ctrl points & lines when editing a certain type point
				if (data->btn_radio1 == 3 && data->editing_points) {
					int i = data->type_point_index;
					if (i > 0) {
						//draw_list->AddCircleFilled(ImVec2(data->ctrl_points[3 * i - 1][0] + origin.x, data->ctrl_points[3 * i - 1][1] + origin.y), 3.0f, IM_COL32(255, 255, 255, 255));
						draw_list->AddRectFilled(ImVec2(data->ctrl_points[3 * i - 1][0] + origin.x - 3.0f, data->ctrl_points[3 * i - 1][1] + origin.y - 3.0f), ImVec2(data->ctrl_points[3 * i - 1][0] + origin.x + 3.0f, data->ctrl_points[3 * i - 1][1] + origin.y + 3.0f), IM_COL32(255, 255, 255, 255));
						draw_list->AddLine(ImVec2(origin.x + data->ctrl_points[3 * i - 1][0], origin.y + data->ctrl_points[3 * i - 1][1]), ImVec2(origin.x + data->points[i][0], origin.y + data->points[i][1]), IM_COL32(255, 255, 255, 255), 1.0f);
					}
					if (i < data->points.size() - 1) {
						//draw_list->AddCircleFilled(ImVec2(data->ctrl_points[3 * i + 1][0] + origin.x, data->ctrl_points[3 * i + 1][1] + origin.y), 3.0f, IM_COL32(255, 255, 255, 255));
						draw_list->AddRectFilled(ImVec2(data->ctrl_points[3 * i + 1][0] + origin.x - 3.0f, data->ctrl_points[3 * i + 1][1] + origin.y - 3.0f), ImVec2(data->ctrl_points[3 * i + 1][0] + origin.x + 3.0f, data->ctrl_points[3 * i + 1][1] + origin.y + 3.0f), IM_COL32(255, 255, 255, 255));
						draw_list->AddLine(ImVec2(origin.x + data->points[i][0], origin.y + data->points[i][1]), ImVec2(origin.x + data->ctrl_points[3 * i + 1][0], origin.y + data->ctrl_points[3 * i + 1][1]), IM_COL32(255, 255, 255, 255), 1.0f);
					}
				}
			}
			draw_list->PopClipRect();
		}

		ImGui::End();
		});
}

float CalDistance(pointf2 pos1, pointf2 pos2) {
	return sqrt(pow(pos1[0] - pos2[0], 2) + pow(pos1[1] - pos2[1], 2));
}

vector<float> Parameterization(vector<pointf2> data_points, string parameterization_type) {
	//Calculate each distance and their sum for normalization
	vector<float> t, alpha, chordalDistance, centripetalDistance, foleyDistance;

	for (int i = 0; i < data_points.size() - 1; i++) {
		chordalDistance.push_back(CalDistance(data_points[i + 1], data_points[i]));
		centripetalDistance.push_back(sqrt(chordalDistance[i]));
	}
	for (int i = 0; i < data_points.size() - 1;i++) {
		if (i < data_points.size() - 2) {
			alpha.push_back((float)M_PI - acos((pow(chordalDistance[i], 2) + pow(chordalDistance[i + 1], 2) - pow(CalDistance(data_points[i + 2], data_points[i]), 2)) / (2.0f * chordalDistance[i] * chordalDistance[i + 1]))); // Law of cosines
			alpha[i] = min(alpha[i], (float)M_PI_2);
		}

		if (i == 0)
			foleyDistance.push_back(chordalDistance[i] * (1.0f + 1.5f * alpha[i] * chordalDistance[i] / (chordalDistance[i] + chordalDistance[i + 1])));
		else if (i == data_points.size() - 2)
			foleyDistance.push_back(chordalDistance[i] * (1.0f + 1.5f * alpha[i - 1] * chordalDistance[i - 1] / (chordalDistance[i - 1] + chordalDistance[i])));
		else
			foleyDistance.push_back(chordalDistance[i] * (1.0f + 1.5f * alpha[i - 1] * chordalDistance[i - 1] / (chordalDistance[i - 1] + chordalDistance[i]) + 1.5f * alpha[i] * chordalDistance[i] / (chordalDistance[i] + chordalDistance[i + 1])));
	}
	float sumChordalDistance = accumulate(chordalDistance.begin(), chordalDistance.end(), 0.0f);
	float sumCentripetalDistance = accumulate(centripetalDistance.begin(), centripetalDistance.end(), 0.0f);
	float sumFoleyDistance = accumulate(foleyDistance.begin(), foleyDistance.end(), 0.0f);

	for (int i = 0;i < data_points.size();i++) {
		if (i == 0) {
			t.push_back(0.0f);
		}
		else {
			if (parameterization_type == UNIFORM)
				t.push_back(t.back() + 1.0f / (float)(data_points.size() - 1));
			else if (parameterization_type == CHORDAL)
				t.push_back(t.back() + chordalDistance[i - 1] / sumChordalDistance);
			else if (parameterization_type == CENTRIPETAL)
				t.push_back(t.back() + centripetalDistance[i - 1] / sumCentripetalDistance);
			else if (parameterization_type == FOLEY)
				t.push_back(t.back() + foleyDistance[i - 1] / sumFoleyDistance);
		}
	}

	return t;
}

vector<pointf2> DrawCubicParametricSpline(vector<float> t, vector<pointf2> data_points, float sampling_period) {
	// Initialize and calculate parameters h, u, b, v
	vector<pointf2> draw_points;
	VectorXf M_x = VectorXf::Zero(data_points.size());
	VectorXf M_y = VectorXf::Zero(data_points.size());
	VectorXf h(data_points.size() - 1), b_x(data_points.size() - 1), b_y(data_points.size() - 1);
	VectorXf u(data_points.size() - 2), v_x(data_points.size() - 2), v_y(data_points.size() - 2), M_mid_x(data_points.size() - 2), M_mid_y(data_points.size() - 2);
	for (int i = 0; i < data_points.size() - 1; i++) {
		h(i) = t[i + 1] - t[i];
		b_x(i) = 6.0f * (data_points[i + 1][0] - data_points[i][0]) / h(i);
		b_y(i) = 6.0f * (data_points[i + 1][1] - data_points[i][1]) / h(i);

		if (i > 0) {
			u(i - 1) = 2.0f * (h(i) + h(i - 1));
			v_x(i - 1) = b_x(i) - b_x(i - 1);
			v_y(i - 1) = b_y(i) - b_y(i - 1);
		}
	}

	if (data_points.size() == 3) {
		M_mid_x(0) = v_x(0) / u(0);
		M_mid_y(0) = v_y(0) / u(0);
	}
	else if (data_points.size() == 4) {
		Matrix2f A;
		A(0, 0) = u(0);
		A(0, 1) = h(1);
		A(1, 0) = h(1);
		A(1, 1) = u(1);
		M_mid_x = A.colPivHouseholderQr().solve(v_x);
		M_mid_y = A.colPivHouseholderQr().solve(v_y);
	}
	else {
		SparseMatrix<float> A(data_points.size() - 2, data_points.size() - 2);
		A.reserve(VectorXi::Constant(data_points.size() - 2, 3));
		for (int i = 0; i < data_points.size() - 2; i++) {
			A.insert(i, i) = u(i);
			if (i > 0)
				A.insert(i, i - 1) = h(i);
			if (i < data_points.size() - 3)
				A.insert(i, i + 1) = h(i + 1);
		}
		A.makeCompressed();

		//solve the three-moment equations "AM_x=v_x", "AM_y=v_y"
		SparseLU<SparseMatrix<float>> solver;
		solver.compute(A);
		M_mid_x = solver.solve(v_x);
		M_mid_y = solver.solve(v_y);
	}
	for (int i = 0;i < M_mid_x.size();i++) {
		M_x(i + 1) = M_mid_x(i);
		M_y(i + 1) = M_mid_y(i);
	}

	for (int i = 0; i < data_points.size() - 1; i++) {
		for (float t1 = t[i]; t1 <= t[i + 1]; t1 += sampling_period) {
			float x = M_x(i) / (6.0f * h(i)) * pow(t[i + 1] - t1, 3) + M_x(i + 1) / (6.0f * h(i)) * pow(t1 - t[i], 3) + (data_points[i + 1][0] / h(i) - M_x(i + 1) * h(i) / 6.0f) * (t1 - t[i]) + (data_points[i][0] / h(i) - M_x(i) * h(i) / 6.0f) * (t[i + 1] - t1);
			float y = M_y(i) / (6.0f * h(i)) * pow(t[i + 1] - t1, 3) + M_y(i + 1) / (6.0f * h(i)) * pow(t1 - t[i], 3) + (data_points[i + 1][1] / h(i) - M_y(i + 1) * h(i) / 6.0f) * (t1 - t[i]) + (data_points[i][1] / h(i) - M_y(i) * h(i) / 6.0f) * (t[i + 1] - t1);
			const pointf2 pos(x, y);
			draw_points.push_back(pos);
		}
	}

	return draw_points;
}

vector<pointf2> InitBezierCurveCtrlPoints(vector<pointf2> data_points) {
	vector<pointf2> ctrl_points(3 * data_points.size() - 2);
	ctrl_points[0] = data_points[0];
	ctrl_points[3 * (data_points.size() - 1)] = data_points[data_points.size() - 1];

	if (data_points.size() == 2) {
		ctrl_points[1][0] = (5.0f * data_points[0][0] + data_points[1][0]) / 6.0f;
		ctrl_points[1][1] = (5.0f * data_points[0][1] + data_points[1][1]) / 6.0f;
		ctrl_points[2][0] = (data_points[0][0] + 5.0f * data_points[1][0]) / 6.0f;
		ctrl_points[2][1] = (data_points[0][1] + 5.0f * data_points[1][1]) / 6.0f;
		return ctrl_points;
	}

	for (int i = 1; i < data_points.size() - 1; i++) {
		ctrl_points[3 * i] = data_points[i];
		Matrix4f A;
		A << -1, 1, 0, 0, 0, 0, -1, 1, 1, 1, 0, 0, 0, 0, 1, 1;
		Vector4f pos, b((data_points[i + 1][0] - data_points[i - 1][0]) / 3.0f, (data_points[i + 1][1] - data_points[i - 1][1]) / 3.0f, 2.0f * data_points[i][0], 2.0f * data_points[i][1]);
		pos = A.colPivHouseholderQr().solve(b);
		const pointf2 pos_1(pos(0), pos(2));
		const pointf2 pos_2(pos(1), pos(3));
		ctrl_points[3 * i - 1] = pos_1;
		ctrl_points[3 * i + 1] = pos_2;
	}
	const pointf2 pos1((data_points[0][0] * 5.0f + ctrl_points[2][0]) / 6.0f, (data_points[0][1] * 5.0f + ctrl_points[2][1]) / 6.0f);
	ctrl_points[1] = pos1;
	const pointf2 pos2((data_points[data_points.size() - 1][0] * 5.0f + ctrl_points[ctrl_points.size() - 3][0]) / 6.0f, (data_points[data_points.size() - 1][1] * 5.0f + ctrl_points[ctrl_points.size() - 3][1]) / 6.0f);
	ctrl_points[ctrl_points.size() - 2] = pos2;

	return ctrl_points;
}

vector<pointf2> DrawCubicBezierCurve(vector<pointf2> data_ctrl_points, float sampling_period) {
	vector<pointf2> draw_points;

	for (int i = 0; i < data_ctrl_points.size() - 3; i += 3) {
		for (float t = 0.0f; t < 1.0f; t += sampling_period) {
			float x = pow(1 - t, 3) * data_ctrl_points[i][0] + 3.0f * t * pow(1.0f - t, 2) * data_ctrl_points[i + 1][0] + 3.0f * t * t * (1.0f - t) * data_ctrl_points[i + 2][0] + pow(t, 3) * data_ctrl_points[i + 3][0];
			float y = pow(1 - t, 3) * data_ctrl_points[i][1] + 3.0f * t * pow(1.0f - t, 2) * data_ctrl_points[i + 1][1] + 3.0f * t * t * (1.0f - t) * data_ctrl_points[i + 2][1] + pow(t, 3) * data_ctrl_points[i + 3][1];
			const pointf2 pos(x, y);
			draw_points.push_back(pos);
		}
	}

	return draw_points;
}

void DrawCurve(ImDrawList* draw_list, float origin_x, float origin_y, vector<pointf2> draw_points, string parameterization_type) {
	ImU32 col = IM_COL32(255, 255, 255, 255);
	if (parameterization_type == UNIFORM)
		col = IM_COL32(255, 165, 0, 255);
	else if (parameterization_type == CHORDAL)
		col = IM_COL32(255, 255, 0, 255);
	else if (parameterization_type == CENTRIPETAL)
		col = IM_COL32(0, 255, 0, 255);
	else if (parameterization_type == FOLEY)
		col = IM_COL32(0, 255, 255, 255);
	else if (parameterization_type == BEZIER)
		col = IM_COL32(254, 67, 101, 255);
	for (int n = 0; n < draw_points.size() - 1; n++) {
		draw_list->AddLine(ImVec2(origin_x + draw_points[n][0], origin_y + draw_points[n][1]), ImVec2(origin_x + draw_points[n + 1][0], origin_y + draw_points[n + 1][1]), col, 2.0f);
	}
}
