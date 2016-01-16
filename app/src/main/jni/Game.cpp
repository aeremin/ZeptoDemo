#include "Game.h"
#include <GLES2/gl2.h>

Game::Game()
    : field_(1.0f, 1.0f)
{
}

void Game::initViewport(int width, int height) {
    glViewport(0, 0, width, height);
}

void Game::update() {
    glClearColor(0.0f, 0.0f, 1.0, 1.0f);
    glClear( GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    field_.render();
}

