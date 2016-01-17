#include "Field.h"

namespace
{
const float cObstacleWidth = 0.3f;
const float cStartObstacleHoleTop = 0.75f;
const float cStartObstacleHoleBottom = 0.25f;
const float cStartObstacleOffset = 0.5f;
const float cMinDistanceBetweenObstacles = 2 * cObstacleWidth;
const float cMaxDistanceBetweenObstacles = 4 * cObstacleWidth;
const float cMinHoleHeight = 0.4;
}


Field::Field(float screenWidthWorld)
    : screenWidthWorld_(screenWidthWorld),
      obstacleBoundingBox_(math::GeomVector2F(0.0f, 0.0f),
                           math::GeomVector2F(cObstacleWidth, screenHeightWorld_))
{
    Obstacle firstObstacle(obstacleBoundingBox_ + offsetVector_(cStartObstacleOffset),
                           cStartObstacleHoleBottom, cStartObstacleHoleTop);
    obstacles_.push_back(firstObstacle);
    update(0.0f);
}

void Field::update(float offset) {
    currentOffset_ = offset;

    while (obstacles_.size() > 1 && obstacles_.front().rightBorder() < -screenWidthWorld_ / 2.0f + offset)
        obstacles_.pop_front();

    while (obstacles_.back().rightBorder() < screenWidthWorld_ / 2.0f + offset)
        generateObstacle_();
}

namespace {
float unitRandom() {
    return float(rand())/float(RAND_MAX);
}
}

void Field::generateObstacle_() {
    float distanceFromLast = cMinDistanceBetweenObstacles +
            (cMaxDistanceBetweenObstacles - cMinDistanceBetweenObstacles) * unitRandom();

    float leftBorder = obstacles_.back().rightBorder() + distanceFromLast;

    float holeTop = 0.0f;
    float holeBottom = 0.0f;
    while (holeTop - holeBottom <cMinHoleHeight){
        holeBottom = unitRandom();
        holeTop = unitRandom();
    }

    Obstacle obstacle(obstacleBoundingBox_ + offsetVector_(leftBorder),
                      screenHeightWorld_ * holeBottom, screenHeightWorld_ * holeTop);
    obstacles_.push_back(obstacle);
}

void Field::render(render::RectangleRenderer& renderer) {
    std::vector<math::Rectangle> rectangles;
    for (const auto& obstacle : obstacles_)
        obstacle.collectRectangles(rectangles);

    renderer.render(rectangles, math::GeomVector2F(currentOffset_, 1.0f));
}

math::GeomVector2F Field::offsetVector_(float offset) {
    return math::GeomVector2F(offset, 0.0f);
}
