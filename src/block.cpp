#include"block.h"
#include"colors.h"
#include "position.h"
#include <raylib.h>
#include <vector>

block::block() {
    cellsize = 30;
    rotatestate = 0;
    colors = cellcolors();
    rowoffset = 0;
    coloffset = 0;
}

void block::draw(int offsetx, int offsety) {
    std::vector<position> tiles = cellposition();
    for (position item : tiles) {
        DrawRectangle(item.col * cellsize + offsetx, item.row * cellsize + offsety, cellsize - 1, cellsize - 1, colors[id]);
    }
}

void block::move(int rows , int cols) {
    rowoffset += rows;
    coloffset += cols;
}

std::vector<position> block::cellposition() {
    std::vector<position> tiles = cells[rotatestate];
    std::vector<position> moved;
    for(position item:tiles) {
        position newpos = position(item.row + rowoffset, item.col + coloffset);
        moved.push_back(newpos);
    }
    return moved;
}

void block::Rotate() {
    rotatestate++;
    if(rotatestate == (int)cells.size()) {
        rotatestate = 0;
    }
}

void block::undoRotate() {
    rotatestate--;
    if(rotatestate == -1) {
        rotatestate = cells.size() - 1;
    }
}