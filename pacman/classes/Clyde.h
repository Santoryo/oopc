// Clyde will turn on crossing to try to move towards Pacman always.
#pragma once
#include "Ghost.h"
#include "Constants.h"
#include "Grid.h"
#include "Pacman.h"

class Clyde : public Ghost
{
private:
    Pacman *pacman;
public:
    Clyde(Grid &grid, int x, int y, Pacman &pacman) : Ghost(grid, x, y) { color = CLYDE_COLOR; this->pacman = &pacman; };
    ~Clyde() = default;
    void randomMovement();
    void move() override;
};
