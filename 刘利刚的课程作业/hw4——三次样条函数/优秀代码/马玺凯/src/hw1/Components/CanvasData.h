#pragma once

#include <UGM/UGM.h>

struct CanvasData {
	std::vector<Ubpa::pointf2> points;
	std::vector<Ubpa::pointf2> lpoints;
	std::vector<Ubpa::vecf2> tangents;
	std::vector<Ubpa::pointf2> tPoints;
	std::vector<float> delta;
	Ubpa::valf2 scrolling{ 0.f,0.f };
	int method{4};
	int selected = -1;  //选择的非切线控制点
	int tselected = -1; //选择的切线控制点
	int continuity = 3; //默认改变切线时C1连续 2: G1 1: G0
	bool opt_enable_grid{ true };
	bool opt_enable_context_menu{ true };
	bool adding_line{ false };
	bool ChangeControlPoint{ false };
};

#include "details/CanvasData_AutoRefl.inl"
