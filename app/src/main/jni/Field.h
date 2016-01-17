#pragma once

#include <deque>

#include "Obstacle.h"
#include "math/GeomVector.h"
#include "render/RectangleRenderer.h"

class Field {
public:
    Field(float screenWidthWorld);

    void update(float offset);

    void render(render::RectangleRenderer& renderer);

private:
    void generateObstacle_();

    static math::GeomVector2F offsetVector_(float offset);

private:
    const float screenHeightWorld_ = 2.0;
    const float screenWidthWorld_;
    float currentOffset_ = 0.0f;

    const math::Rectangle obstacleBoundingBox_;

    std::deque<Obstacle> obstacles_;
};
