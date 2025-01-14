#include "Grid.h"

void Grid::loadMap(std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        throw std::runtime_error("Error opening file");
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int n;
        while (iss >> n) {
            row.push_back(n);
        }
        map.push_back(row);
    }
}

size_t Grid::getRows() {
    return map.size();
}

size_t Grid::getCols() {
    return map[0].size();
}

size_t Grid::getCell(int row, int col) {
    return map[row][col];
}

void Grid::setCell(int row, int col, int value) {
    map[row][col] = value;
}

