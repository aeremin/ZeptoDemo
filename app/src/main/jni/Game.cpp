#include "Game.h"
#include <GLES2/gl2.h>

using namespace std::chrono;

Game::Game()
    : field_(2.0f, 2.0f),
      ball_({0.25f, 0.0f}),
      start_(steady_clock::now())
{
}

void Game::initViewport(int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::update() {
    glClearColor(0.0f, 0.0f, 1.0, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    float offset = duration_cast<milliseconds>(steady_clock::now() - start_).count();
    field_.update(0.0001 * offset);
    ball_.update(0.0001 * offset);
    if (ball_.getCollisionCircle().center[1] < -0.5f)
        ball_.punch();
    field_.render();
    ball_.render();
    // TODO: intersection check
    // TODO: count scores
}

