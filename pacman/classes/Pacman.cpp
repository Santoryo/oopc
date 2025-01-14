#include "Pacman.h"

Pacman::Pacman()
{
    x = 0;
    y = 0;
    direction = 0;
}


void Pacman::move(int direction)
{
    float speed = 0.1;

    if (direction == 0)
    {
        x = x - speed * 1;
    }
    else if (direction == 1)
    {
        x = x + speed * 1;
    }
    else if (direction == 2)
    {
        y = y - speed * 1;
    }
    else if (direction == 3)
    {
        y = y + speed * 1;
    }
}

void Pacman::draw(QPainter &painter)
{
    painter.setBrush(Qt::yellow);
    painter.setPen(Qt::yellow);
    painter.drawRect(x, y, 30, 30);
}