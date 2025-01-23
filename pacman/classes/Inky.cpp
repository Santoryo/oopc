#include "Inky.h"

void Inky::randomMovement()
{
    while (true)
    {
        int random = 1 + rand() % 8;
        if (random <= 4 && canMove(UP) && direction != DOWN)
        {
            nextDirection = UP;
            break;
        }
        if (random <= 5 && canMove(DOWN) && direction != UP)
        {
            nextDirection = DOWN;
            break;
        }
        if (random <= 6 && canMove(LEFT) && direction != RIGHT)
        {
            nextDirection = LEFT;
            break;
        }
        if (random <= 8 && canMove(RIGHT) && direction != LEFT)
        {
            nextDirection = RIGHT;
            break;
        }
    }
}

void Inky::move()
{
    int newX = x;
    int newY = y;

    if (x % TILE_SIZE == 0 && y % TILE_SIZE == 0)
    {
        std::array<int, 2> cell = grid.findCellInBounds(x, y);
        row = cell[0];
        col = cell[1];

        randomMovement();

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
        newX -= GHOST_SPEED;
        break;
    case RIGHT:
        newX += GHOST_SPEED;
        break;
    case UP:
        newY -= GHOST_SPEED;
        break;
    case DOWN:
        newY += GHOST_SPEED;
        break;
    }

    x = newX;
    y = newY;

    teleportBack();
}