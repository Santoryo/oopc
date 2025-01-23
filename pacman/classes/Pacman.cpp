#include "Pacman.h"
#include "Constants.h"

int a = 45 * 16;
int alen = 270 * 16;

enum MouthState
{
    FULL_OPEN,
    SEMI_OPEN,
    CLOSED
};

int mouthState = SEMI_OPEN;

Pacman::Pacman(Grid &grid) : grid(grid) {
    direction = NONE;
    nextDirection = NONE;
}

void Pacman::move() {
    int newX = x;
    int newY = y;

    if (nextDirection != NONE && canMove(nextDirection))
    {
        if ((direction == LEFT || direction == RIGHT) && (nextDirection == LEFT || nextDirection == RIGHT))
        {
            direction = nextDirection;
            nextDirection = NONE;
        }
        else if ((direction == UP || direction == DOWN) && (nextDirection == UP || nextDirection == DOWN))
        {
            direction = nextDirection;
            nextDirection = NONE;
        }
    }

    if (x % TILE_SIZE == 0 && y % TILE_SIZE == 0)
    {
        std::array<int, 2> cell = grid.findCellInBounds(x, y);
        row = cell[0];
        col = cell[1];

        if (nextDirection != NONE && canMove(nextDirection))
        {
            direction = nextDirection;
            nextDirection = NONE;
        }
        if (!canMove(direction))
        {
            direction = NONE;
        }
    }

    switch (direction)
    {
        case LEFT:
            newX -= PACMAN_SPEED;
            break;
        case RIGHT:
            newX += PACMAN_SPEED;
            break;
        case UP:
            newY -= PACMAN_SPEED;
            break;
        case DOWN:
            newY += PACMAN_SPEED;
            break;
    }

    x = newX;
    y = newY;

    teleportBack();
}

void Pacman::setDirection(int dir)
{
    nextDirection = dir;
}

bool Pacman::canMove(int dir)
{
    auto [rRow, rCol] = grid.findCellInBounds(x, y);

    switch (dir) {
        case LEFT:
            return grid.getCell(rRow, rCol - 1) != WALL;
        case RIGHT:
            return grid.getCell(rRow, rCol + 1) != WALL;
        case UP:
            return grid.getCell(rRow - 1, rCol) != WALL;
        case DOWN:
            return grid.getCell(rRow + 1, rCol) != WALL;
        default:
            return false;
    }
}

void Pacman::setPos(size_t x, size_t y)
{
    this->x = x;
    this->y = y;
}

void Pacman::draw(QPainter &painter)
{
    switch (direction) {
        case LEFT:
            a = 225 * 16;
            break;
        case RIGHT:
            a = 45 * 16;
            break;
        case UP:
            a = 135 * 16;
            break;
        case DOWN:
            a = 315 * 16;
            break;
    }
    int centerX = x + TILE_SIZE / 2 - TILE_SIZE / 4;
    int centerY = y + TILE_SIZE / 2 - TILE_SIZE / 4;

    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::yellow);

    painter.drawPie(centerX, centerY, TILE_SIZE / 2, TILE_SIZE / 2, a, alen);
}

void Pacman::teleportBack()
{
    if(x <= 0)
    {
        x = grid.getCols() * TILE_SIZE - TILE_SIZE;
    }
    if(x >= grid.getCols() * TILE_SIZE)
    {
        x = 0;
    }
}

void Pacman::respawn()
{
    x = grid.getSpawnCoordinates(PACMAN)[0];
    y = grid.getSpawnCoordinates(PACMAN)[1];
    direction = NONE;
    nextDirection = NONE;
}   