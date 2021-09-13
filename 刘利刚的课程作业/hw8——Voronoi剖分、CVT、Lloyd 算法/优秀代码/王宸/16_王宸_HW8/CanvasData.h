#pragma once

#include <UGM/UGM.h>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
//#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Delaunay_triangulation_2.h>

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef K::Point_2 Point;

struct CanvasData {
	std::vector<Point> points;
	Ubpa::valf2 scrolling{ 0.f,0.f };
	bool opt_enable_grid{ false };
	bool opt_enable_context_menu{ true };
	bool adding_line{ false };

	bool add_point{ false };
	bool enable_delaunay{ false };
	bool enable_voronoi{ false };
	bool enable_lloyd{ false };
	int points_num{ 10 };
	int it_n{ 0 };
	int max_iteration_number{ 50 };

	Delaunay dt;
};

#include "details/CanvasData_AutoRefl.inl"
