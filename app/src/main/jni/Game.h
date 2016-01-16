#pragma once

#include "Field.h"

class Game {
public:
    Game();

    void initViewport(int width, int height);
    void update();

private:
    Field field_;
};

