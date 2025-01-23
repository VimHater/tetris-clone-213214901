#include "raylib.h"
#include "game.h"
int main ()
{
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);
    
    Color bg = {76, 79, 105, 255};
    Grid grid = Grid();
    grid.Print();
    
    game Game = game();
    Oblock block = Oblock();
    block.move(4, 3);
    
    while(WindowShouldClose() == false) {
        Game.handleinput();
        BeginDrawing();
        ClearBackground(bg);
        Game.draw();
        EndDrawing();
    }
    
    CloseWindow();
}
