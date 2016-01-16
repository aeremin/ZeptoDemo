#pragma once

#include "render/RectangleRenderer.h"

class Game {
public:
    void initViewport(int width, int height);
    void update();

private:
    render::RectangleRenderer rr_;
};

