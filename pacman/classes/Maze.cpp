#include "Maze.h"
#include "Constants.h"

Maze::Maze()
{
    grid.loadMap("assets/map.txt");
}

void Maze::drawGrid(QPainter &painter)
{
    int rows = grid.getRows();
    int cols = grid.getCols();
    for (size_t row = 0; row < rows; ++row)
    {
        for (size_t col = 0; col < cols; ++col)
        {
            drawCell(painter, row, col);
        }
    }
}

void Maze::drawCell(QPainter &painter, size_t row, size_t col)
{
    int cellValue = grid.getCell(row, col);
    if (cellValue == WALL)
    {
        painter.setBrush(Qt::NoBrush);
        painter.setPen(QPen(Qt::blue, 2));

        if (row == 0 || grid.getCell(row - 1, col) != WALL)
        {
            painter.drawLine(col * TILE_SIZE, row * TILE_SIZE, (col + 1) * TILE_SIZE, row * TILE_SIZE);
        }

        if (row == grid.getRows() - 1 || grid.getCell(row + 1, col) != WALL)
        {
            painter.drawLine(col * TILE_SIZE, (row + 1) * TILE_SIZE, (col + 1) * TILE_SIZE, (row + 1) * TILE_SIZE);
        }

        if (col == 0 || grid.getCell(row, col - 1) != WALL)
        {
            painter.drawLine(col * TILE_SIZE, row * TILE_SIZE, col * TILE_SIZE, (row + 1) * TILE_SIZE);
        }

        if (col == grid.getCols() - 1 || grid.getCell(row, col + 1) != WALL)
        {
            painter.drawLine((col + 1) * TILE_SIZE, row * TILE_SIZE, (col + 1) * TILE_SIZE, (row + 1) * TILE_SIZE);
        }
    }
    if (cellValue == COIN)
    {
        painter.setBrush(Qt::yellow);
        painter.setPen(Qt::NoPen);
        int radius = TILE_SIZE / 10;
        painter.drawEllipse(
            col * TILE_SIZE + TILE_SIZE / 2 - radius,
            row * TILE_SIZE + TILE_SIZE / 2 - radius,
            radius * 2,
            radius * 2);
    }
    if (cellValue == POWERUP)
    {
        painter.setBrush(Qt::white);
        painter.setPen(Qt::NoPen);
        int radius = TILE_SIZE / 5;
        painter.drawEllipse(
            col * TILE_SIZE + TILE_SIZE / 2 - radius,
            row * TILE_SIZE + TILE_SIZE / 2 - radius,
            radius * 2,
            radius * 2);
    }
}