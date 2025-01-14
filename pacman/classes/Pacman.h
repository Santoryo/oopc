#pragma once
#include <iostream>
#include <QWidget>
#include <QPainter>
#include "Grid.h"

class Pacman {
private:
    size_t x;
    size_t y;
    int direction;
    Grid &grid;
public:
    Pacman(Grid &grid);
    ~Pacman() = default;
    void move();
    void draw(QPainter &painter);
    void setDirection(int direction);
    void setPos(size_t x, size_t y);
    size_t getX() { return x; }
    size_t getY() { return y; }
    int getDirection() { return direction; }
};