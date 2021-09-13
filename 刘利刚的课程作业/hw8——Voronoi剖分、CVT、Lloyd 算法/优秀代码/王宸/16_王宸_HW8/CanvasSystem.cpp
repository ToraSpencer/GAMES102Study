#include "CanvasSystem.h"

#include "../Components/CanvasData.h"

#include <_deps/imgui/imgui.h>

#include <spdlog/spdlog.h>

#define CGAL_MESH_2_OPTIMIZER_VERBOSE
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/lloyd_optimize_mesh_2.h>
#include <CGAL/Delaunay_mesher_2.h>
#include <CGAL/Delaunay_mesh_face_base_2.h>
#include <CGAL/Delaunay_mesh_vertex_base_2.h>
#include <CGAL/Delaunay_mesh_size_criteria_2.h>


using namespace Ubpa;

constexpr float square_width = 250.f;

void RandomPoints(CanvasData*);
void Lloyd(CanvasData*);

void DrawDelaunay(CanvasData*, ImDrawList*, const ImVec2);
void DrawVoronoi(CanvasData*, ImDrawList*, const ImVec2);

void CanvasSystem::OnUpdate(Ubpa::UECS::Schedule& schedule) {
	schedule.RegisterCommand([](Ubpa::UECS::World* w) {
		auto data = w->entityMngr.GetSingleton<CanvasData>();
		if (!data)
			return;

		if (ImGui::Begin("Canvas")) {
			ImGui::Checkbox("Enable grid", &data->opt_enable_grid);
			ImGui::Checkbox("Enable context menu", &data->opt_enable_context_menu);
			ImGui::Text("Mouse Left: drag to add lines,\nMouse Right: drag to scroll, click for context menu.");

			ImGui::Text("points number: "); ImGui::SameLine();
			ImGui::PushItemWidth(100.f);
			ImGui::InputInt("", &data->points_num);
			ImGui::PopItemWidth();
			ImGui::SameLine();
			if (ImGui::Button("Random generation")) {
				data->add_point = true;
			}//ImGui::SameLine();
			if (ImGui::Button("Delaunay")) {
				data->enable_delaunay ^= true;
			}ImGui::SameLine();
			if (ImGui::Button("Voronoi")) {
				data->enable_voronoi ^= true;
			}ImGui::SameLine();
			if (ImGui::Button("Do Lloyd")) {
				data->it_n = 0;
				data->enable_lloyd ^= true;
			}ImGui::SameLine(); 
			ImGui::Text("max iteration number: "); ImGui::SameLine(); 
			ImGui::PushItemWidth(100.f);
			ImGui::InputInt(" ", &data->max_iteration_number);
			ImGui::PopItemWidth();

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
			ImVec2 origin(canvas_p0.x + data->scrolling[0], canvas_p0.y + data->scrolling[1]); // Lock scrolled origin
			const pointf2 mouse_pos_in_canvas(io.MousePos.x - origin.x, io.MousePos.y - origin.y);

			const float mouse_threshold_for_pan = data->opt_enable_context_menu ? -1.0f : 0.0f;
			if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
			{
				data->scrolling[0] += io.MouseDelta.x;
				data->scrolling[1] += io.MouseDelta.y;
			}

			draw_list->PushClipRect(canvas_p0, canvas_p1, true);
			
			origin = ImVec2(origin.x + 200, origin.y + 50);
			if(data->add_point) RandomPoints(data);
			data->add_point = false;

			draw_list->AddRectFilled(ImVec2(origin.x, origin.y), ImVec2(origin.x + square_width, origin.y + square_width), IM_COL32(255, 255, 255, 200));

			for (auto& p : data->points) {
				draw_list->AddCircleFilled(ImVec2((float)p[0] + origin.x, (float)p[1] + origin.y), 3.f, IM_COL32(166, 27, 41, 255));
			}

			if (data->enable_delaunay) DrawDelaunay(data, draw_list, origin);
			if (data->enable_voronoi) DrawVoronoi(data, draw_list, origin);

			if (data->enable_lloyd) {
				if (data->it_n < data->max_iteration_number) {
					Lloyd(data);
					data->it_n++;
					spdlog::info("Lloyd epoch {} done", data->it_n);
				}
				else {
					data->enable_lloyd = false;
					data->it_n = 0;
				}
			}

			draw_list->PopClipRect();
		}

		ImGui::End();
	});
}

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_mesh_vertex_base_2<K>                Vb;
typedef CGAL::Delaunay_mesh_face_base_2<K>                  Fb;
typedef CGAL::Triangulation_data_structure_2<Vb, Fb>        Tds;
typedef CGAL::Constrained_Delaunay_triangulation_2<K, Tds>  CDT;
typedef CGAL::Delaunay_mesh_size_criteria_2<CDT>            Criteria;
typedef CGAL::Delaunay_mesher_2<CDT, Criteria>              Mesher;
typedef CDT::Vertex_handle Vertex_handle;

typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef K::Point_2 Point;

void RandomPoints(CanvasData* data) {
	data->add_point = true;
	data->points.clear();
	for (int i = 0; i < data->points_num; i++) {
		float x = Ubpa::rand01<float>() * square_width;
		float y = Ubpa::rand01<float>() * square_width;
		data->points.push_back(Point(x, y));
	}
	data->dt = Delaunay(data->points.begin(), data->points.end());
}

void Lloyd(CanvasData* data) {
	CDT cdt;
	Vertex_handle va = cdt.insert(CDT::Point(0, 0));
	Vertex_handle vb = cdt.insert(CDT::Point(0, square_width));
	Vertex_handle vc = cdt.insert(CDT::Point(square_width, square_width));
	Vertex_handle vd = cdt.insert(CDT::Point(square_width, 0));
	for (auto& v : data->points) cdt.insert((CDT::Point)v);
	cdt.insert_constraint(va, vb);
	cdt.insert_constraint(vb, vc);
	cdt.insert_constraint(vc, vd);
	cdt.insert_constraint(vd, va);
	CGAL::lloyd_optimize_mesh_2(cdt, CGAL::parameters::max_iteration_number = 1);
	data->points.clear();
	int index = 0;
	for (Vertex_handle vh : cdt.finite_vertex_handles()) {
		index++;
		if (index < 5) continue;
		data->points.push_back(vh->point());
	}
	data->dt = Delaunay(data->points.begin(), data->points.end());
}

const ImU32 delaunay_line_col = IM_COL32(37, 61, 36, 255);

void DrawDelaunay(CanvasData* data, ImDrawList* draw_list, const ImVec2 origin) {
	auto& dt = data->dt;
	Delaunay::Finite_faces_iterator fit;
	for (fit = dt.finite_faces_begin(); fit != dt.finite_faces_end(); fit++) {
		const ImVec2 a((float)fit->vertex(0)->point().x() + origin.x, (float)fit->vertex(0)->point().y() + origin.y);
		const ImVec2 b((float)fit->vertex(1)->point().x() + origin.x, (float)fit->vertex(1)->point().y() + origin.y);
		const ImVec2 c((float)fit->vertex(2)->point().x() + origin.x, (float)fit->vertex(2)->point().y() + origin.y);
		draw_list->AddLine(a, b, delaunay_line_col, 1.2f);
		draw_list->AddLine(b, c, delaunay_line_col, 1.2f);
		draw_list->AddLine(c, a, delaunay_line_col, 1.2f);
	}
}

const ImU32 voronoi_line_col = IM_COL32(19, 72, 87, 255);

struct Cropped_voronoi_from_delaunay {
	std::list<K::Segment_2> m_cropped_vd;
	K::Iso_rectangle_2 m_bbox;
	Cropped_voronoi_from_delaunay(const K::Iso_rectangle_2& bbox) :m_bbox(bbox) {}
	template <class RSL>
	void crop_and_extract_segment(const RSL& rsl) {
		CGAL::Object obj = CGAL::intersection(rsl, m_bbox);
		const K::Segment_2* s = CGAL::object_cast<K::Segment_2>(&obj);
		if (s) m_cropped_vd.push_back(*s);
	}
	void operator<<(const K::Ray_2& ray) { crop_and_extract_segment(ray); }
	void operator<<(const K::Line_2& line) { crop_and_extract_segment(line); }
	void operator<<(const K::Segment_2& seg) { crop_and_extract_segment(seg); }
};

void DrawVoronoi(CanvasData* data, ImDrawList* draw_list, const ImVec2 origin) {
	auto& dt = data->dt;
	Delaunay::Edge_iterator eit;
	K::Iso_rectangle_2 bbox(0, 0, square_width, square_width);
	Cropped_voronoi_from_delaunay vor(bbox);
	//extract the cropped Voronoi diagram
	data->dt.draw_dual(vor);
	for (K::Segment_2& seg : vor.m_cropped_vd) {
		ImVec2 a((float)seg.source().x() + origin.x, (float)seg.source().y() + origin.y);
		ImVec2 b((float)seg.target().x() + origin.x, (float)seg.target().y() + origin.y);
		draw_list->AddLine(a, b, voronoi_line_col, 1.2f);
	}
}