#pragma once

#include "GeomVector.h"
namespace math {

struct Circle {
    Circle(GeomVector2F center__, float radius__)
        : center(center__), radius(radius__) {}

    const GeomVector2F center;
    const float radius;
};

}