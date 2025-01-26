#pragma once

#include<vector>
#include<map>
#include"position.h"
#include"colors.h"

class block {
    public:
        block();
        void draw(int offsetx, int offsety);
        void move(int rows, int cols);
        std::vector<position> cellposition();
        void Rotate();
        void undoRotate();
        int id;
        std::map<int,std::vector<position>> cells;
    private:
        int cellsize;
        int rotatestate;
        std::vector<Color> colors;
        int rowoffset;
        int coloffset;
};