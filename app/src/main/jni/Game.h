#pragma once
#include <chrono>
#include "Field.h"

class Game {
public:
    Game();

    void initViewport(int width, int height);
    void update();

private:
    Field field_;

    std::chrono::steady_clock::time_point start_;
};

