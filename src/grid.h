#pragma once
#include<vector>
#include<raylib.h>
class Grid {
    public:
        Grid();
        void Init();
        void Print();
        void draw();
        bool outofbound(int row, int col);
        bool emptycell(int row, int col);
        int grid[20][20];
    private:
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};