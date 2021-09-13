// This file is generated by Ubpa::USRefl::AutoRefl

#pragma once

#include <USRefl/USRefl.h>

template<>
struct Ubpa::USRefl::TypeInfo<CanvasData>
    : Ubpa::USRefl::TypeInfoBase<CanvasData>
{
    static constexpr AttrList attrs = {};

    static constexpr FieldList fields = {
        Field{"input_points", &CanvasData::input_points},
        Field{"point_set1", &CanvasData::point_set1},
        Field{"point_set2", &CanvasData::point_set2},
        Field{"point_set3", &CanvasData::point_set3},
        Field{"point_set4", &CanvasData::point_set4},
        Field{"scrolling", &CanvasData::scrolling},
        Field{"opt_enable_grid", &CanvasData::opt_enable_grid},
        Field{"opt_enable_context_menu", &CanvasData::opt_enable_context_menu},
        Field{"opt_fitting_methods", &CanvasData::opt_fitting_methods},
        Field{"opt_fitting_step", &CanvasData::opt_fitting_step},
        Field{"opt_sigma", &CanvasData::opt_sigma},
        Field{"opt_max_exponent", &CanvasData::opt_max_exponent},
        Field{"opt_lambda", &CanvasData::opt_lambda},
    };
};

