#include "Ghost.h"
#include "Constants.h"

int nextDirection = NONE;
int destinationX = 0;
int destinationY = 0;

void Ghost::setDirection(int dir)
{
    nextDirection = dir;
}

bool Ghost::canMove(int dir)
{
    auto [rRow, rCol] = grid.findCellInBounds(x, y);

    switch (dir)
    {
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

void Ghost::teleportBack()
{
    if (x <= 0)
    {
        x = grid.getCols() * TILE_SIZE - TILE_SIZE;
    }
    if (x >= grid.getCols() * TILE_SIZE)
    {
        x = 0;
    }
}

void Ghost::setPos(size_t x, size_t y)
{
    this->x = x;
    this->y = y;
}

int Ghost::getRow()
{
    return row;
}

int Ghost::getCol()
{
    return col;
}

void Ghost::draw(QPainter &painter) {
    painter.setBrush(this->color);
    painter.setPen(this->color);

    if(isScared)
    {
        painter.setBrush(Qt::blue);
        painter.setPen(Qt::blue);
    }


    float scale = 0.8f;

    int scaledTileSize = static_cast<int>(TILE_SIZE * scale);
    QRect headRect(x + (TILE_SIZE - scaledTileSize) / 2, y + (TILE_SIZE - scaledTileSize) / 2, scaledTileSize, scaledTileSize);
    painter.drawRoundedRect(headRect, scaledTileSize / 2, scaledTileSize / 2);

    QPolygon bottomPolygon;
    int waveHeight = scaledTileSize / 4;
    int offsetX = (TILE_SIZE - scaledTileSize) / 2;
    int offsetY = (TILE_SIZE - scaledTileSize) / 2 + scaledTileSize / 2;

    bottomPolygon << QPoint(x + offsetX, y + offsetY);
    bottomPolygon << QPoint(x + offsetX + scaledTileSize / 4, y + offsetY + waveHeight);
    bottomPolygon << QPoint(x + offsetX + scaledTileSize / 2, y + offsetY);
    bottomPolygon << QPoint(x + offsetX + 3 * scaledTileSize / 4, y + offsetY + waveHeight);
    bottomPolygon << QPoint(x + offsetX + scaledTileSize, y + offsetY);
    bottomPolygon << QPoint(x + offsetX + scaledTileSize, y + offsetY + scaledTileSize / 2);
    bottomPolygon << QPoint(x + offsetX, y + offsetY + scaledTileSize / 2);

    painter.drawPolygon(bottomPolygon);

    painter.setBrush(Qt::black);
    painter.setPen(Qt::black);

    int eyeWidth = scaledTileSize / 5;
    int eyeHeight = scaledTileSize / 5;
    int eyeOffsetX = scaledTileSize / 4;
    int eyeOffsetY = scaledTileSize / 4;

    QRect leftEyeRect(x + offsetX + eyeOffsetX, y + offsetY - eyeOffsetY, eyeWidth, eyeHeight);
    QRect rightEyeRect(x + offsetX + 2 * eyeOffsetX, y + offsetY - eyeOffsetY, eyeWidth, eyeHeight);

    painter.drawEllipse(leftEyeRect);
    painter.drawEllipse(rightEyeRect);
}

void Ghost::setScared()
{
    isScared = true;
    direction = direction * -1;
}

void Ghost::setNormal()
{
    isScared = false;
    direction = direction * -1;
}