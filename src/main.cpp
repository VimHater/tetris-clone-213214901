#include "raylib.h"
#include "grid.h"
int main ()
{
    Color bg = {76, 79, 105, 255};
    Grid grid = Grid();
    grid.Print();

    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);
    
    while(WindowShouldClose() == false) {
        
        BeginDrawing();
        ClearBackground(bg);
        grid.draw();
        
        EndDrawing();
    }
    CloseWindow();
}
