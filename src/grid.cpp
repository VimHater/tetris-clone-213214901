#include "grid.h"
#include <iostream>
#include <raylib.h>
#include <vector>
#include "colors.h"
Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Init();
    colors = cellcolors();
}

void Grid::Init() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            std::cout << grid[row][col];
        }
        std::cout << std::endl;
    }
}

void Grid::draw() {
    for(int row = 0; row < numRows; row++){
        for (int col = 0; col < numCols; col++) {
            int cellValue = grid[row][col];
            DrawRectangle(col*cellSize + 1, row*cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}