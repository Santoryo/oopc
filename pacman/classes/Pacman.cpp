#include "Pacman.h"
#include "Constants.h"

int angle = 0;

Pacman::Pacman(Grid &grid) : grid(grid) {
    x = 100;
    y = 100;
    direction = 0;
}

void Pacman::move() {
    int newX = x, newY = y;

    auto [row, col] = grid.findClosestCell(x, y);
    bool movement = true;

    switch (direction) {
        case LEFT:
            if(grid.getCell(row, col - 1) == WALL)
            {
                movement = false;
                break;
            }
            newX -= PACMAN_SPEED;
            break;
        case RIGHT:
            if(grid.getCell(row, col + 1) == WALL)
            {
                movement = false;
                break;
            }
            newX += PACMAN_SPEED;
            break;
        case UP:
            if(grid.getCell(row - 1, col) == WALL)
            {
                movement = false;
                break;
            }
            newY -= PACMAN_SPEED;
            break;
        case DOWN:
            if(grid.getCell(row + 1, col) == WALL)
            {
                movement = false;
                break;
            }
            newY += PACMAN_SPEED;
            break;
    }

    if(movement)
    {
        newX = x;
        newY = y;
    }
    std::cout << "X: " << x << " Y: " << y << std::endl;

    if(col < 0)
    {
        x = 21 * TILE_SIZE;
    }
    if(col > 21)
    {
        x = 0;
    }
}

void Pacman::setDirection(int direction) {
    this->direction = direction;

    switch (direction) {
        case LEFT:
            angle = 180 * 16;
            break;
        case RIGHT:
            angle = 0;
            break;
        case UP:
            angle = 90 * 16;
            break;
        case DOWN:
            angle = 270 * 16;
            break;
    }
}

void Pacman::setPos(size_t x, size_t y) {
    this->x = x;
    this->y = y;
}

void Pacman::draw(QPainter &painter) {
    painter.setBrush(Qt::red);
    painter.setPen(Qt::red);

    int centerX = x + TILE_SIZE / 2 - TILE_SIZE / 4;
    int centerY = y + TILE_SIZE / 2 - TILE_SIZE / 4;

    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::yellow);

    painter.drawPie(centerX, centerY, TILE_SIZE / 2, TILE_SIZE / 2, angle, 300 * 16);
}
