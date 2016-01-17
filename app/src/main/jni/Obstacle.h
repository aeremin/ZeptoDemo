#pragma once

#include "math/Rectangle.h"
#include "math/Circle.h"

class Obstacle {
public:
    Obstacle(const math::Rectangle& boundingBox, float holeBottom, float holeTop);

    bool intersects(const math::Circle& circle) const;

    float leftBorder() const;
    float rightBorder() const;

    void collectRectangles(std::vector<math::Rectangle>& collectTo) const;

private:
    const math::Rectangle upperRectangle_, lowerRectangle_;
};

