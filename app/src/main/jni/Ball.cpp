#include "Ball.h"

namespace
{
const float cBallRadius = 0.2f;
const float cGravitationalAcceleration = 10.3f;
const float cPunchVerticalSpeed = 5.3f;
}

Ball::Ball(math::GeomVector2F startPosition) {
    currentPosition_ = startPosition;
    lastPunchPosition_ = startPosition;
}

void Ball::update(float offset) {
    auto timeFromLastPunch = offset - lastPunchPosition_[0];
    auto verticalOffset = cPunchVerticalSpeed * timeFromLastPunch
                          - cGravitationalAcceleration * timeFromLastPunch * timeFromLastPunch;
    currentPosition_ = lastPunchPosition_ + math::GeomVector2F(timeFromLastPunch, verticalOffset);
}

void Ball::punch() {
    lastPunchPosition_ = currentPosition_;
}

void Ball::render(render::CircleRenderer& renderer) {
    renderer.render(getCollisionCircle());
}

math::Circle Ball::getCollisionCircle() const {
    return math::Circle(currentPosition_, cBallRadius);
}

