#pragma once
#include <iostream>
#include <QWidget>
#include <QPainter>
#include "Grid.h"
#include <QGraphicsItem>

class Pacman  {
private:
    size_t x;
    size_t y;
    int direction;
    Grid &grid;
    int row;
    int col;
    int nextDirection;
    int isPoweredUp;
public:
    Pacman(Grid &grid);
    ~Pacman() = default;
    void move();
    void toggleMode() { isPoweredUp = !isPoweredUp; }
    void draw(QPainter &painter);
    void setDirection(int direction);
    void setPos(size_t x, size_t y);
    size_t getX() { return x; }
    size_t getY() { return y; }
    size_t getRow() { return row; }
    size_t getCol() { return col; }
    int getDirection() { return direction; }
    bool canMove(int dir);
    void teleportBack();
    void respawn();
};