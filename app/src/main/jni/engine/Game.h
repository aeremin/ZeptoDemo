#pragma once
#include <chrono>
#include <memory>
#include "Field.h"
#include "Ball.h"
#include "../render/RectangleRenderer.h"
#include "../render/NumberRenderer.h"

namespace engine {

class Game {
public:
    Game();

    void initViewport(int width, int height);

    void setXScale(float xScale);

    void update();
    void onTouch();

    void pause();
    void resume();

private:
    void createRenderers_();
    void startGame_();

    float xScale_ = 4.0 / 3.0;

    std::unique_ptr<Field> field_;
    std::unique_ptr<Ball> ball_;

    std::unique_ptr<render::NumberRenderer> scoreRenderer_;
    std::unique_ptr<render::CircleRenderer> circleRenderer_;
    std::unique_ptr<render::RectangleRenderer> rectangleRenderer_;

    std::chrono::steady_clock::time_point start_;

    bool paused_ = false;
    std::chrono::steady_clock::time_point pauseStart_;
};

}