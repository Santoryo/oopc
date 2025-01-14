#pragma once
#include <iostream>
#include <QWidget>
#include <QPainter>

class Pacman {
private:
    size_t x;
    size_t y;
    int direction;
public:
    Pacman();
    ~Pacman() = default;
    void move(int direction);
    void draw(QPainter &painter);
};