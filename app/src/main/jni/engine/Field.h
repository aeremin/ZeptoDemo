#pragma once

#include <deque>

#include "Obstacle.h"
#include "../math/GeomVector.h"
#include "../render/RectangleRenderer.h"

namespace engine {

class Field {
public:
    Field(float screenWidthWorld);
    void setScreenWidthWorld(float screenWidthWorld);

    void update(float offset);
    void render(render::RectangleRenderer &renderer);

    bool intersects(const math::Circle &circle) const;

    int getObstaclesCountOnLeftOf(float position) const;

private:
    void generateObstacle_();

    std::vector<math::Rectangle> getAllRectangles_() const;

    static math::GeomVector2F offsetVector_(float offset);

private:
    float screenWidthWorld_;
    float currentOffset_;

    const math::Rectangle obstacleBoundingBox_;

    std::deque<Obstacle> obstacles_;
    int deletedObstacles_ = 0;
};

}