#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <array>

class Grid {
private:
    std::vector<std::vector<int>> map;
public:
    Grid() = default;
    void loadMap(std::string filename);
    size_t getRows();
    size_t getCols();
    size_t getCell(int row, int col);
    void setCell(int row, int col, int value);
    bool canMoveTo(int row, int col);
    std::array<int, 2> getCoordinates(int x, int y);
    std::array<int, 2> getSpawnCoordinates(int type);
    std::array<int, 2> findClosestCell(int x, int y);
};