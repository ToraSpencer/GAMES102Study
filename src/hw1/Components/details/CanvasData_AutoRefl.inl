// This file is generated by Ubpa::USRefl::AutoRefl

#pragma once

#include <USRefl/USRefl.h>

template<>
struct Ubpa::USRefl::TypeInfo<CanvasData> :
    TypeInfoBase<CanvasData>
{
#ifdef UBPA_USREFL_NOT_USE_NAMEOF
    static constexpr char name[11] = "CanvasData";
#endif
    static constexpr AttrList attrs = {};
    static constexpr FieldList fields = {
        Field {TSTR("points"), &Type::points},
        Field {TSTR("scrolling"), &Type::scrolling, AttrList {
            Attr {TSTR(UMeta::initializer), []()->Ubpa::valf2{ return { 0.f,0.f }; }},
        }},
        Field {TSTR("opt_enable_grid"), &Type::opt_enable_grid, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { true }; }},
        }},
        Field {TSTR("opt_enable_context_menu"), &Type::opt_enable_context_menu, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { true }; }},
        }},
        Field {TSTR("adding_line"), &Type::adding_line, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { false }; }},
        }},
        Field {TSTR("enable01"), &Type::enable01, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { true }; }},
        }},
        Field {TSTR("enable02"), &Type::enable02, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { true }; }},
        }},
        Field {TSTR("enable03"), &Type::enable03, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { true }; }},
        }},
        Field {TSTR("enable04"), &Type::enable04, AttrList {
            Attr {TSTR(UMeta::initializer), []()->bool{ return { true }; }},
        }},
        Field {TSTR("highest"), &Type::highest, AttrList {
            Attr {TSTR(UMeta::initializer), []()->int{ return 1; }},
        }},
        Field {TSTR("coordx"), &Type::coordx},
        Field {TSTR("coordy1"), &Type::coordy1},
        Field {TSTR("coordy2"), &Type::coordy2},
        Field {TSTR("coordy3"), &Type::coordy3},
        Field {TSTR("coordy4"), &Type::coordy4},
        Field {TSTR("lamda"), &Type::lamda, AttrList {
            Attr {TSTR(UMeta::initializer), []()->float{ return 1.0f; }},
        }},
    };
};

