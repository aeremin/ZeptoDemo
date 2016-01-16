#include "Obstacle.h"
#include <cassert>

Obstacle::Obstacle(const math::Rectangle& boundingBox, float holeBottom, float holeTop)
    : upperRectangle_(math::GeomVector2F(boundingBox.minCorner[0], holeTop), boundingBox.maxCorner),
      lowerRectangle_(math::GeomVector2F(boundingBox.maxCorner[0], holeBottom), boundingBox.minCorner)
{
    assert(holeBottom < holeTop);
}

float Obstacle::leftBorder() const {
    return upperRectangle_.minCorner[0];
}

float Obstacle::rightBorder() const {
    return upperRectangle_.maxCorner[0];
}

bool Obstacle::intersects(const math::Circle &circle) const {
    // TODO: implement
    return false;
}

void Obstacle::collectRectangles(std::vector<math::Rectangle>& collectTo) const {
    collectTo.push_back(upperRectangle_);
    collectTo.push_back(lowerRectangle_);
}
