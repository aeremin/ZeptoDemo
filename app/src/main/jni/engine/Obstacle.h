#pragma once

#include "../math/Rectangle.h"
#include "../math/Circle.h"

namespace engine {

class Obstacle {
public:
    Obstacle(const math::Rectangle &boundingBox, float holeBottom, float holeTop);

    float leftBorder() const;

    float rightBorder() const;

    void collectRectangles(std::vector<math::Rectangle> &collectTo) const;

private:
    const math::Rectangle upperRectangle_, lowerRectangle_;
};

}