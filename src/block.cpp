#include"block.h"
#include "colors.h"

block::block() {
    cellsize = 30;
    rotatestate = 0;
    colors = cellcolors();
}

void block::draw