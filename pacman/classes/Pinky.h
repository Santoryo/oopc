// Inky will always turn right on crossing, otherwise it will prioritize 
#pragma once
#include "Ghost.h"
#include "Constants.h"
#include "Grid.h"
#include "Pacman.h"

class Pinky : public Ghost
{
private:
    Pacman *pacman;
public:
    Pinky(Grid &grid, int x, int y, Pacman &pacman) : Ghost(grid, x, y) { color = PINKY_COLOR; this->pacman = &pacman; };
    ~Pinky() = default;
    void randomMovement();
    void move() override;
};
