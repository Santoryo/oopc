#include "Game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    maze = new Maze(this);
    maze->show();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::gameLoop);
    timer->start(16); // ~60 FPS
}

void Game::gameLoop()
{
    maze->update();
}