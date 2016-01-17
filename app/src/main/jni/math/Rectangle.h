#pragma once

#include "GeomVector.h"
#include "Circle.h"

namespace math {

struct Rectangle {
    Rectangle(GeomVector2F firstCorner, GeomVector2F secondCorner);

    const GeomVector2F minCorner;
    const GeomVector2F maxCorner;
};

Rectangle operator+(const Rectangle& rect, const GeomVector2F& shift);


bool intersects(const Circle& c, const Rectangle& r);
}

