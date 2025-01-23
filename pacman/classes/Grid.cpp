#include "Grid.h"
#include "Constants.h"

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

bool Grid::canMoveTo(int row, int col) {
    return map[row][col] == PATH || map[row][col] == COIN;
}

std::array<int, 2> Grid::getCoordinates(int x, int y) {
    return {y / TILE_SIZE, x / TILE_SIZE};
}

std::array<int, 2> Grid::getSpawnCoordinates(int type) {
    for (size_t row = 0; row < getRows(); ++row) {
        for (size_t col = 0; col < getCols(); ++col) {
            if (getCell(row, col) == type) {
                return {col * TILE_SIZE, row * TILE_SIZE};
            }
        }
    }
    return {0, 0};
}

std::vector<std::array<int, 2>> Grid::positionsOf(int type)
{
    std::vector<std::array<int, 2>> positions;
    for (size_t row = 0; row < getRows(); ++row)
    {
        for (size_t col = 0; col < getCols(); ++col)
        {
            if (getCell(row, col) == type)
            {
                std::array<int, 2> pos = {col * TILE_SIZE, row * TILE_SIZE};
                positions.push_back(pos);
            }
        }
    }
    return positions;
}


std::array<int, 2> Grid::findClosestCell(int x, int y) {
    int row = y / TILE_SIZE;
    int col = x / TILE_SIZE;

    int dx = x % TILE_SIZE;
    int dy = y % TILE_SIZE;

    if (dx >= TILE_SIZE / 2) {
        col++;
    }
    if (dy >= TILE_SIZE / 2) {
        row++;
    }

    return {row, col};
}

std::array<int, 2> Grid::findCellInBounds(int x, int y) {
    int row = y / TILE_SIZE;
    int col = x / TILE_SIZE;

    return {row, col};
}

bool Grid::isValidCell(int row, int col) {
    return row >= 0 && row < getRows() && col >= 0 && col < getCols();
}

bool Grid::isWall(int row, int col) {
    return map[row][col] == WALL;
}