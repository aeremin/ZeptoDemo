#include "Rectangle.h"

namespace math {
Rectangle::Rectangle(GeomVector2F firstCorner, GeomVector2F secondCorner)
    : minCorner(min(firstCorner, secondCorner)), maxCorner(max(firstCorner, secondCorner))
{}

Rectangle operator+(const Rectangle &rect, const GeomVector2F &shift) {
    return {rect.minCorner + shift, rect.maxCorner + shift};
}

namespace
{
bool between(float a, float b, float x){
    return (x >= a && x <= b);
}
}

bool intersects(const Circle& c, const Rectangle& r) {
    for (int axis = 0; axis < 2; ++axis) {
        if (between(r.minCorner[axis], r.maxCorner[axis], c.center[axis]) &&
            between(r.minCorner[1 - axis] - c.radius, r.maxCorner[1 - axis] + c.radius, c.center[1 - axis]))
                return true;
    }

    std::vector<GeomVector2F> corners = {r.minCorner, r.maxCorner,
                                         GeomVector2F(r.minCorner[0], r.maxCorner[1]),
                                         GeomVector2F(r.maxCorner[0], r.minCorner[1])};

    auto insideTheCircle = [&](const GeomVector2F& v) {
        return (v - c.center).lengthSquared() < c.radius * c.radius;
    };

    return std::any_of(begin(corners), end(corners), insideTheCircle);
}
}