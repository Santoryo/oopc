#pragma once
#include <QPainter>
#include "Grid.h"
#include "Constants.h"

class Ghost {
protected:
    Grid &grid;
    int x, y;
    int row, col;
    int direction;
    QColor color;
    bool isScared = false;
public:
    int nextDirection;
    Ghost(Grid &grid, int startX, int startY) : grid(grid), x(startX), y(startY), direction(RIGHT) {
        auto cell = grid.findCellInBounds(x, y);
        row = cell[0];
        col = cell[1];
    };

    void draw(QPainter &painter);
    void setDirection(int dir);
    bool canMove(int dir);
    void setPos(size_t x, size_t y);
    void teleportBack();
    void setScared();
    void setNormal();
    bool getScared() { return isScared; }
    virtual void move() = 0;

    int getRow();
    int getCol();
};