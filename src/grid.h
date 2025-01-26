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
        int clearfullrow();
        int grid[20][20];
    private:
        bool rowfull(int row);
        void clearrow(int row);
        void moverowdown(int row, int num);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};