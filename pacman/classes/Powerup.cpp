#include "Powerup.h"
#include "Constants.h"

Powerup::Powerup()
{
    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &Powerup::toggleVisibility);
    timer->start(250);
}

void Powerup::toggleVisibility()
{
    isVisible = !isVisible;
}

void Powerup::draw(QPainter &painter, int x, int y)
{
    if (!isVisible)
    {
        return;
    }

    painter.setBrush(QColor(POINTS_COLOR));
    painter.setPen(Qt::NoPen);
    int radius = TILE_SIZE / 3;
    painter.drawEllipse(
        x * TILE_SIZE + TILE_SIZE / 2 - radius,
        y * TILE_SIZE + TILE_SIZE / 2 - radius,
        radius * 2,
        radius * 2);
}