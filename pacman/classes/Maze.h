#pragma once
#include "Grid.h"
#include "Pacman.h"
#include <QWidget>
#include <QPainter>

class Maze : public QWidget {
    Q_OBJECT

public:
    Maze(QWidget *parent = nullptr);
    ~Maze() = default;
protected:
    void paintEvent(QPaintEvent *event) override;
private:
    Grid grid;
    void drawGrid(QPainter &painter);
    void drawCell(QPainter &painter, size_t row, size_t col);
};
