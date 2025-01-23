#pragma once
#include<vector>
#include<map>
#include"position.h"
#include"colors.h"

class block {
    public:
        block();
        int id;
        std::map<int, std::vector<position>> cells;
    private:
        int cellsize;
        int rotatestate;
        std::vector<Color> colors;
};