#include "raylib.h"
#include "game.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
double lastupdatetime = 0;

bool eventtrigger(double interval) {
    double currenttime = GetTime();
    if(currenttime - lastupdatetime >= interval) {
        lastupdatetime = currenttime;
        return true;
    }
    return false;
}

double speed(double &time) {
    
    return (0.2 - time/1000);
}
int main ()
{
    InitWindow(510, 620, "Tetris Clone");
    SetTargetFPS(60);
    
    Font font = LoadFontEx("font/font.ttf", 64, 0, 0);
    
    Color bg = {76, 79, 105, 255};
    Grid grid = Grid();
    grid.Print();
    
    game Game = game();
    Oblock block = Oblock();
    block.move(4, 3);
    
    while(WindowShouldClose() == false) {
        UpdateMusicStream(Game.theme_music);
        Game.handleinput();
        
        double time = GetTime();
        if(eventtrigger(speed(time))) {
            Game.moveblockdown();
        }
        DrawTextEx(font, "SCORE", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "NEXT", {370, 175}, 38, 2, WHITE);
        if(Game.gameover) {
            DrawTextEx(font, "GAME OVER", {300, 450}, 38, 2, WHITE);
            DrawTextEx(font, "U're DEAD", { 300, 500 }, 38, 2, WHITE);
        }
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, pcbgreen);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, pcbgreen);
        char scoretxt[10];
        sprintf(scoretxt, "%d", Game.score);
        Vector2 textsize = MeasureTextEx(font, scoretxt, 38, 2);
        DrawTextEx(font, scoretxt, {320+ (170 - textsize.x)/2, 65}, 38, 2, WHITE);
        BeginDrawing();
        ClearBackground(bg);
        Game.draw();
        EndDrawing();
    }
    
    CloseWindow();
}
