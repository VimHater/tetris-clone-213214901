#pragma once

class Grid{
    public:
        Grid();
        void Init();
        void Print();
        int grid[20][20];
    private:
        int numRows;
        int numCols;
        int cellSize;
};