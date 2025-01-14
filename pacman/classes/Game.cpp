#include "Game.h"
#include "Pacman.h"
#include <QKeyEvent>

Game::Game(QWidget *parent) : QWidget(parent), pacman(maze->grid) {
    maze = new Maze();

    resize(maze->grid.getCols() * TILE_SIZE, maze->grid.getRows() * TILE_SIZE);

    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);

    std::array<int, 2> pos = maze->grid.getSpawnCoordinates(PACMAN);
    pacman.setPos(pos[0], pos[1]);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Game::gameLoop);
    timer->start(16); // ~60 FPS
}

void Game::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    maze->drawGrid(painter);

    painter.setBrush(Qt::yellow);
    painter.setPen(QPen(Qt::yellow, 2));
    pacman.draw(painter);
}

void Game::gameLoop()
{
    pacman.move();
    update();
}



void Game::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left:
            pacman.setDirection(LEFT);
            break;
        case Qt::Key_Right:
            pacman.setDirection(RIGHT);
            break;
        case Qt::Key_Up:
            pacman.setDirection(UP);
            break;
        case Qt::Key_Down:
            pacman.setDirection(DOWN);
            break;
        default:
            break;
    }
}