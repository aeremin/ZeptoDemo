#ifndef ZEPTODEMO_OBSTACLE_H
#define ZEPTODEMO_OBSTACLE_H


#include "math/Rectangle.h"
#include "math/Circle.h"

class Obstacle {
public:
    Obstacle(const math::Rectangle& boundingBox, float holeBottom, float holeTop);

    bool intersects(const math::Circle& circle) const;

    float leftBorder() const;
    float rightBorder() const;

private:
    const math::Rectangle upperRectangle_, lowerRectangle_;
};


#endif //ZEPTODEMO_OBSTACLE_H
