#pragma once
#include "Grid.h"
#include "Pacman.h"
#include "Powerup.h"
#include <QWidget>
#include <QPainter>

class Maze {
public:
    Maze();
    ~Maze() = default;
    void drawGrid(QPainter &painter);
    Grid grid;
    Powerup* powerup;
private:
    void drawCell(QPainter &painter, size_t row, size_t col);
};
