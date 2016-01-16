#ifndef ZEPTODEMO_FIELD_H
#define ZEPTODEMO_FIELD_H

#include <deque>

#include "Obstacle.h"
#include "math/GeomVector.h"
#include "render/RectangleRenderer.h"

class Field {
public:
    Field(float screenWidthWorld, float screenHeightWorld);

    void update(float offset);

    void render();

private:
    void generateObstacle_();

    static math::GeomVector2F offsetVector_(float offset);

private:
    const float screenWidthWorld_, screenHeightWorld_;
    float currentOffset_ = 0.0f;

    const math::Rectangle obstacleBoundingBox_;

    std::deque<Obstacle> obstacles_;
    render::RectangleRenderer rectangleRenderer_;

};


#endif //ZEPTODEMO_FIELD_H
