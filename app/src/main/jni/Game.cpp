#include "Game.h"
#include <GLES2/gl2.h>

using namespace std::chrono;

Game::Game()
    : ball_({0.25f, 0.0f}),
      start_(steady_clock::now())
{
}

void Game::initViewport(int width, int height) {
    glViewport(0, 0, width, height);
    float xScale = float(width) / float(height);
    field_.reset(new Field(2.0f * xScale));
    rectangleRenderer_.reset(new render::RectangleRenderer(xScale));
    circleRenderer_.reset(new render::CircleRenderer(xScale));
}

void Game::update() {
    glClearColor(0.0f, 0.0f, 1.0, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    float offset = duration_cast<milliseconds>(steady_clock::now() - start_).count();
    field_->update(0.0001 * offset);
    ball_.update(0.0001 * offset);
    if (ball_.getCollisionCircle().center[1] < -0.5f)
        ball_.punch();
    field_->render(*rectangleRenderer_);
    ball_.render(*circleRenderer_);
    // TODO: intersection check
    // TODO: count scores
}

