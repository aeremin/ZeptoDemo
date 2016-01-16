#include "Obstacle.h"

Obstacle::Obstacle(Rectangle boundingBox, float holeBottom, float holeTop)
    : upperRectangle_(GeomVector2F(boundingBox.minCorner[0], holeTop), boundingBox.maxCorner),
      lowerRectangle_(GeomVector2F(boundingBox.maxCorner[0], holeBottom), boundingBox.minCorner)
{
}

float Obstacle::leftBorder() const {
    return upperRectangle_.minCorner[0];
}

float Obstacle::rightBorder() const {
    return upperRectangle_.maxCorner[0];
}

bool Obstacle::intersects(const Circle &circle) const {
    // TODO: implement
    return false;
}
