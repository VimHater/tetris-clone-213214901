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
    gameover = false;
    score = 0;
    InitAudioDevice();
    
    theme_music = LoadMusicStream("sound-effect/music.mp3");
    PlayMusicStream(theme_music);
    rotate = LoadSound("sound-effect/rotate.wav");
    clear  = LoadSound("sound-effect/clear.mp3");
}

game::~game() {
    UnloadMusicStream(theme_music);
    UnloadSound(rotate);
    UnloadSound(clear);
    CloseAudioDevice();
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
    currentblock.draw(11, 11);
    switch (nextblock.id) {
        case 3:
            nextblock.draw(255, 290);
            break;
        case 4:
            nextblock.draw(255, 280);
            break;
        default:
            nextblock.draw(270, 270);
            break;
    }
}

void game::handleinput() {
    int keypressed = GetKeyPressed();
    if(gameover && keypressed) {
        gameover = false;
        reset();
    }
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
            updatescore(0, 1);
            break;
        case KEY_S:
            moveblockdown();
            updatescore(0, 1);
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
    if(!gameover) {
        currentblock.move(0, -1);
        if(isblockoutside() || !blockfits()) {
            currentblock.move(0, 1);
        }
    }
}

void game::moveblockright() {
    if(!gameover) {
        currentblock.move(0, 1);
        if(isblockoutside() || !blockfits()) {
            currentblock.move(0, -1);
        }
    }
}

void game::moveblockdown() {
    if(!gameover) {
        currentblock.move(1, 0);
        if(isblockoutside() || !blockfits()) {
            currentblock.move(-1, 0);
            lockblock();
        }
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
    if(!gameover) {
        currentblock.Rotate();
        if(isblockoutside() || !blockfits()) {
            currentblock.undoRotate();
        } else {
            PlaySound(rotate);
        }
    }
}

void game::lockblock() {
    std::vector<position> tiles = currentblock.cellposition();
    for (position item : tiles) {
        grid.grid[item.row][item.col] = currentblock.id;
    }
    currentblock = nextblock;
    if(!blockfits()) {
        gameover = true;
    }
    nextblock = randomblock();
    int rowscleared = grid.clearfullrow();
    if(rowscleared) {
        PlaySound(clear);
        updatescore(rowscleared, 0);
    }
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

void game::reset() {
    grid.Init();
    blocks = allblock();
    currentblock = randomblock();
    nextblock = randomblock();
    score = 0;
}

void game::updatescore(int linecleared, int moveddown) {
    switch(linecleared) {
        case 1:
            score += 100;
            break;
        case 2:
            score += 300;
            break;
        case 3:
            score += 500;
            break;
        default:
            break;
    }
    score += moveddown;
}