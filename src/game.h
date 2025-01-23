#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <vector>
class game {
    public:
        game();
        Grid grid;
        block randomblock();
        std::vector<block> allblock();
        void draw();
        void handleinput();
        void moveblockleft();
        void moveblockright();
        void moveblockdown();
    private:
        bool isblockoutside();
        void rotateblock();
        std::vector<block> blocks;
        block currentblock;
        block nextblock;
};