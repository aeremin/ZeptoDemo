#ifndef ZEPTODEMO_OBSTACLE_H
#define ZEPTODEMO_OBSTACLE_H


#include "math/Rectangle.h"
#include "math/Circle.h"

class Obstacle {
public:
    Obstacle(Rectangle boundingBox, float holeBottom, float holeTop);

    bool intersects(const Circle& circle) const;

    float leftBorder() const;
    float rightBorder() const;

private:
    const Rectangle upperRectangle_, lowerRectangle_;
};


#endif //ZEPTODEMO_OBSTACLE_H
