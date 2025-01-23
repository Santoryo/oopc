// Blinky will try to move towards the the player
#pragma once
#include "Ghost.h"
#include "Constants.h"
#include "Grid.h"
#include "Pacman.h"

class Blinky : public Ghost
{
private:
    Pacman *pacman;
public:
    Blinky(Grid &grid, int x, int y, Pacman &pacman) : Ghost(grid, x, y) { color = BLINKY_COLOR; this->pacman = &pacman; };
    ~Blinky() = default;
    void randomMovement();
    void move() override;
};
