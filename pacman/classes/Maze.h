#pragma once
#include "Grid.h"
#include "Pacman.h"
#include <QWidget>
#include <QPainter>

class Maze {
public:
    Maze();
    ~Maze() = default;
    void drawGrid(QPainter &painter);
    Grid grid;
private:
    void drawCell(QPainter &painter, size_t row, size_t col);
};
