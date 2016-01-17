#pragma once
#include <chrono>
#include <memory>
#include "Field.h"
#include "Ball.h"

class Game {
public:
    Game();

    void initViewport(int width, int height);
    void update();

private:
    std::unique_ptr<Field> field_;
    Ball ball_;

    std::unique_ptr<render::CircleRenderer> circleRenderer_;
    std::unique_ptr<render::RectangleRenderer> rectangleRenderer_;

    std::chrono::steady_clock::time_point start_;
};

