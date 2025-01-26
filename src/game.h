#pragma once
#include "grid.h"
#include "blocks.cpp"
#include <raylib.h>
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
        int score;
        bool gameover;
        ~game();
        Music theme_music;
    private:
        bool isblockoutside();
        void rotateblock();
        void lockblock();
        bool blockfits();
        void reset();
        void updatescore(int linecleared, int moveddown);
        std::vector<block> blocks;
        block currentblock;
        block nextblock;
        Sound rotate;
        Sound clear;
};