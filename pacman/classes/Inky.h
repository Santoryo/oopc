// Inky will always turn right on crossing, otherwise it will prioritize 
#pragma once
#include "Ghost.h"
#include "Constants.h"
#include "Grid.h"
#include "Pacman.h"

class Inky : public Ghost
{
private:
    Pacman *pacman;
public:
    Inky(Grid &grid, int x, int y, Pacman &pacman) : Ghost(grid, x, y) { color = INKY_COLOR; this->pacman = &pacman; };
    ~Inky() = default;
    void randomMovement();
    void move() override;
};
