#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

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
    void updateMap();
};