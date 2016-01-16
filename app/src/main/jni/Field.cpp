#include "Field.h"

namespace
{
const float cObstacleWidth = 0.1f;
const float cStartObstacleHoleTop = 0.75f;
const float cStartObstacleHoleBottom = 0.25f;
const float cStartObstacleOffset = 0.5f;
const float cMinDistanceBetweenObstacles = 0.3;
const float cMaxDistanceBetweenObstacles = 0.6;
const float cMinHoleHeight = 0.4;
}


Field::Field(float screenWidthWorld, float screenHeightWorld)
    : screenWidthWorld_(screenWidthWorld),
      screenHeightWorld_(screenHeightWorld),
      obstacleBoundingBox_(math::GeomVector2F(0.0f, 0.0f),
                           math::GeomVector2F(cObstacleWidth, screenHeightWorld))
{
    Obstacle firstObstacle(obstacleBoundingBox_ + offsetVector_(cStartObstacleOffset * screenWidthWorld),
                           cStartObstacleHoleBottom, cStartObstacleHoleTop);
    obstacles_.push_back(firstObstacle);
    update(0.0f);
}

void Field::update(float offset) {
    currentOffset_ = offset;
    while (obstacles_.back().rightBorder() < screenWidthWorld_ + offset)
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

    Obstacle obstacle(obstacleBoundingBox_ + offsetVector_(leftBorder), holeBottom, holeTop);
    obstacles_.push_back(obstacle);
}

void Field::render() {
    std::vector<math::Rectangle> rectangles;
    for (const auto& obstacle : obstacles_)
        obstacle.collectRectangles(rectangles);

    rectangleRenderer_.render(rectangles, offsetVector_(currentOffset_));
}

math::GeomVector2F Field::offsetVector_(float offset) {
    return math::GeomVector2F(offset, 0.0f);
}
