#pragma once
#include "math/GeomVector.h"
#include "math/Circle.h"
#include "render/CircleRenderer.h"

class Ball {
public:
    Ball(math::GeomVector2F startPosition);

    void update(float offset);

    void punch();

    void render(render::CircleRenderer& renderer);

    math::Circle getCollisionCircle() const;

private:
    math::GeomVector2F currentPosition_;
    math::GeomVector2F lastPunchPosition_;
};
