#include "Game.h"
#include <GLES2/gl2.h>

using namespace std::chrono;

Game::Game()
    : start_(steady_clock::now())
{
}

void Game::initViewport(int width, int height) {
    glViewport(0, 0, width, height);
    xScale_ = float(width) / float(height);
    rectangleRenderer_.reset(new render::RectangleRenderer);
    rectangleRenderer_->setXScale(xScale_);
    rectangleRenderer_->setColor(math::GeomVector3F(0.5f, 0.5f, 0.5f));
    circleRenderer_.reset(new render::CircleRenderer);
    circleRenderer_->setXScale(xScale_);
    circleRenderer_->setColor(math::GeomVector3F(0.3f, 0.7f, 0.2f));
    restart_();
}

void Game::update() {
    glClearColor(0.0f, 0.0f, 1.0, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    float offset = 0.0001 * duration_cast<milliseconds>(steady_clock::now() - start_).count();
    field_->update(offset);
    ball_->update(offset);
    rectangleRenderer_->setGlobalOffset(math::GeomVector2F(offset, 0.0f));
    circleRenderer_->setGlobalOffset(math::GeomVector2F(offset, 0.0f));
    field_->render(*rectangleRenderer_);
    ball_->render(*circleRenderer_);

    if (field_->intersects(ball_->getCollisionCircle()))
        restart_();

    // TODO: count scores
}

void Game::onTouch() {
    ball_->punch();
}

void Game::restart_() {
    start_ = steady_clock::now();
    field_.reset(new Field(2.0f * xScale_));
    ball_.reset(new Ball(math::GeomVector2F{-0.5f * xScale_, 0.0f}));
}
