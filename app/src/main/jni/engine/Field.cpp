#include "Field.h"

namespace engine {

namespace {
    const float cScreenTopWorld = 1.0f;
    const float cScreenBottomWorld = -cScreenTopWorld;
    const float cScreenHeightWorld = cScreenTopWorld - cScreenBottomWorld;

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
          obstacleBoundingBox_(math::GeomVector2F(0.0f, cScreenBottomWorld),
                               math::GeomVector2F(cObstacleWidth, cScreenTopWorld)) {
    Obstacle firstObstacle(obstacleBoundingBox_ + offsetVector_(cStartObstacleOffset),
                           cStartObstacleHoleBottom, cStartObstacleHoleTop);
    obstacles_.push_back(firstObstacle);
    update(0.0f);
}

void Field::update(float offset) {
    while (obstacles_.size() > 1 &&
           obstacles_.front().rightBorder() < -screenWidthWorld_ / 2.0f + offset)
        obstacles_.pop_front();

    while (obstacles_.back().rightBorder() < screenWidthWorld_ / 2.0f + offset)
        generateObstacle_();
}

namespace {
    float unitRandom() {
        return 2.0f * float(rand()) / float(RAND_MAX) - 1.0f;
    }
}

void Field::generateObstacle_() {
    float distanceFromLast = cMinDistanceBetweenObstacles +
                             (cMaxDistanceBetweenObstacles - cMinDistanceBetweenObstacles) *
                             abs(unitRandom());

    float leftBorder = obstacles_.back().rightBorder() + distanceFromLast;

    float holeTop = 0.0f;
    float holeBottom = 0.0f;
    while (holeTop - holeBottom < cMinHoleHeight) {
        holeBottom = cScreenTopWorld * unitRandom();
        holeTop = cScreenTopWorld * unitRandom();
    }

    Obstacle obstacle(obstacleBoundingBox_ + offsetVector_(leftBorder),
                      holeBottom, holeTop);
    obstacles_.push_back(obstacle);
}

void Field::render(render::RectangleRenderer &renderer) {
    renderer.render(getAllRectangles_());
}

std::vector<math::Rectangle> Field::getAllRectangles_() const {
    std::vector<math::Rectangle> rectangles;
    for (const auto &obstacle : obstacles_)
        obstacle.collectRectangles(rectangles);
    return rectangles;
}

math::GeomVector2F Field::offsetVector_(float offset) {
    return math::GeomVector2F(offset, 0.0f);
}

bool Field::intersects(const math::Circle &circle) const {
    if (cScreenTopWorld - fabs(circle.center[1]) < circle.radius)
        return true; // Intersects floor/ceiling

    auto allRectangles = getAllRectangles_();

    return std::any_of(begin(allRectangles), end(allRectangles),
                       [&](const math::Rectangle &r) {
                           return math::intersects(circle, r);
                       });

}


}