#include "Ball.h"

namespace engine {

namespace {
    const float cBallRadius = 0.09f;
    const float cGravitationalAcceleration = 15.0f;
    const float cPunchVerticalSpeed = 3.0f;
}

Ball::Ball(math::GeomVector2F startPosition)
        : startPosition_(startPosition),
          currentPosition_(startPosition) {
    punch();
}

void Ball::update(float offset) {
    auto timeFromLastPunch = offset - lastPunchPosition_[0] + startPosition_[0];
    auto verticalOffset = cPunchVerticalSpeed * timeFromLastPunch
                          - cGravitationalAcceleration * timeFromLastPunch * timeFromLastPunch;
    currentPosition_ =
            lastPunchPosition_ + math::GeomVector2F(timeFromLastPunch, verticalOffset);
}

void Ball::punch() {
    lastPunchPosition_ = currentPosition_;
}

void Ball::render(render::CircleRenderer &renderer) {
    renderer.render(getCollisionCircle());
}

math::Circle Ball::getCollisionCircle() const {
    return math::Circle(currentPosition_, cBallRadius);
}

}