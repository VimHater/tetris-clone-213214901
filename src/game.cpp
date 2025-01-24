#include "game.h"
#include "grid.h"
#include "position.h"
#include <chrono>
#include <cstdlib>
#include <raylib.h>
#include <vector>
game::game() {
    grid = Grid();
    blocks = {Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Tblock()};
    currentblock = randomblock();
    nextblock = randomblock();
}

block game::randomblock() {
    if(blocks.empty()) {
        blocks = allblock();
    }
    auto now = std::chrono::high_resolution_clock::now();
    auto nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();
    
    srand(static_cast<unsigned int>(nanoseconds));    
    
    int randomindex= rand() % blocks.size();
    block block = blocks[randomindex];
    blocks.erase(blocks.begin() + randomindex);
    
    return block;
}

std::vector<block> game::allblock() {
    return {Iblock(), Jblock(), Lblock(), Oblock(), Sblock(), Tblock()};
}

void game::draw() {
    grid.draw();
    currentblock.draw();
}

void game::handleinput() {
    int keypressed = GetKeyPressed();
    switch (keypressed) {
        case KEY_LEFT:
        moveblockleft();
        break;
        case KEY_A:
        moveblockleft();
        break;
        
        case KEY_D:
        moveblockright();
        break;
        case KEY_RIGHT:
        moveblockright();
        break;
        
        case KEY_DOWN:
        moveblockdown();
        break;
        case KEY_S:
        moveblockdown();
        break;
        
        case KEY_UP:
        rotateblock();
        break;
        case KEY_W:
        rotateblock();
        break;
    }
}

void game::moveblockleft() {
    currentblock.move(0, -1);
    if(isblockoutside() || !blockfits()) {
        currentblock.move(0, 1);
    }
}

void game::moveblockright() {
    currentblock.move(0, 1);
    if(isblockoutside() || !blockfits()) {
        currentblock.move(0, -1);
    }
}

void game::moveblockdown() {
    currentblock.move(1, 0);
    if(isblockoutside() || !blockfits()) {
        currentblock.move(-1, 0);
        lockblock();
    }
}

bool game::isblockoutside() {
    std::vector<position> tiles = currentblock.cellposition();
    for(position item : tiles) {
        if(grid.outofbound(item.row, item.col)) {
            return true;
        }
    }
    return false;
}

void game::rotateblock() {
    currentblock.Rotate();
    if(isblockoutside() || !blockfits()) {
        currentblock.undoRotate();
    }
}

void game::lockblock() {
    std::vector<position> tiles = currentblock.cellposition();
    for (position item : tiles) {
        grid.grid[item.row][item.col] = currentblock.id;
    }
    nextblock = randomblock();
    currentblock = nextblock;
}

bool game::blockfits() {
    std::vector<position> tiles = currentblock.cellposition();
    for (position item : tiles) {
        if(!grid.emptycell(item.row, item.col)) {
            return false;
        }
    }
    return true;
}