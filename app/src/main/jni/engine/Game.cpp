#include "Game.h"
#include <GLES2/gl2.h>

#include "../Logging.h"
#include <string>

using namespace std::chrono;

namespace engine {

namespace {
    const math::GeomVector3F cBackGroundColor = {182 / 256.f, 225 / 256.f, 252 / 256.f};
    const math::GeomVector3F cBallColor = {0.3f, 0.7f, 0.2f};
    const math::GeomVector3F cObstaclesColor = {0.5f, 0.5f, 0.5f};

    const float cGameSpeed = 0.0002f;
}


Game::Game() {
    createRenderers_();
    startGame_();
}

void Game::initViewport(int width, int height) {
    LOGI("initViewport");
    glViewport(0, 0, width, height);
    setXScale(float(width) / float(height));
}

void Game::createRenderers_() {
    rectangleRenderer_.reset(new render::RectangleRenderer);
    rectangleRenderer_->setColor(cObstaclesColor);
    circleRenderer_.reset(new render::CircleRenderer);
    circleRenderer_->setColor(cBallColor);
    scoreRenderer_.reset(new render::NumberRenderer);
    scoreRenderer_->setColor(cBallColor);
}

void Game::setXScale(float xScale) {
    rectangleRenderer_->setXScale(xScale);
    circleRenderer_->setXScale(xScale);
    scoreRenderer_->setXScale(xScale);
    field_->setScreenWidthWorld(2.0f * xScale);
    xScale_ = xScale;
}

void Game::update() {
    if (paused_)
        return;

    glClearColor(cBackGroundColor[0], cBackGroundColor[1], cBackGroundColor[2], 1.0f);
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    float timeOffset =
            cGameSpeed * duration_cast<milliseconds>(steady_clock::now() - start_).count();
    field_->update(timeOffset);
    ball_->update(timeOffset);
    rectangleRenderer_->setGlobalOffset(math::GeomVector2F(timeOffset, 0.0f));
    circleRenderer_->setGlobalOffset(math::GeomVector2F(timeOffset, 0.0f));
    field_->render(*rectangleRenderer_);
    ball_->render(*circleRenderer_);

    auto ballCircle = ball_->getCollisionCircle();
    scoreRenderer_->render(field_->getObstaclesCountOnLeftOf(ballCircle.center[0] - ballCircle.radius),
                           math::GeomVector2F(-xScale_ + 0.1f, 0.7f));

    if (field_->intersects(ballCircle))
    {
        LOGI("Game lost");
        startGame_();
    }
}

void Game::onTouch() {
    ball_->punch();
}

void Game::startGame_() {
    start_ = steady_clock::now();
    field_.reset(new Field(2.0f * xScale_));
    ball_.reset(new Ball(math::GeomVector2F{-0.5f * xScale_, 0.0f}));
}


void Game::pause() {
    paused_ = true;
    pauseStart_ = steady_clock::now();
}

void Game::resume() {
    paused_ = false;
    start_ += steady_clock::now() - pauseStart_;
}
}