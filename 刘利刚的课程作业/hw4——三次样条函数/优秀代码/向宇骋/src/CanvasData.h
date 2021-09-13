#pragma once

#include <UGM/UGM.h>

struct CanvasData {
	std::vector<Ubpa::pointf2> points;
	std::vector<Ubpa::pointf2> ctrl_points;
	Ubpa::valf2 scrolling{ 0.f,0.f };
	bool opt_enable_grid{ true };
	bool opt_enable_context_menu{ true };
	bool adding_line{ false };

	bool opt_equidistant{ false };
	bool opt_chordal{ false };
	bool opt_centripetal{ false };
	bool opt_foley{ true };
	int btn_radio1{ 0 };
	int btn_radio2{ 0 };

	Ubpa::pointf2 selected_type_point;
	Ubpa::pointf2 selected_ctrl_point1;
	Ubpa::pointf2 selected_ctrl_point2;
	bool editing_points{ false };
	bool editing_type_points{ false };
	bool editing_ctrl_points{ false };
	int type_point_index{ 0 };
	int ctrl_point_index{ 0 };
};

#include "details/CanvasData_AutoRefl.inl"
