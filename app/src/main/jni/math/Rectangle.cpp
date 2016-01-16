#include "Rectangle.h"

namespace math {
Rectangle::Rectangle(GeomVector2F firstCorner, GeomVector2F secondCorner)
    : minCorner(min(firstCorner, secondCorner)), maxCorner(max(firstCorner, secondCorner))
{}

Rectangle operator+(const Rectangle &rect, const GeomVector2F &shift) {
    return {rect.minCorner + shift, rect.maxCorner + shift};
}

}