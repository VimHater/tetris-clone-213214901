#include "raylib.h"
#include <vector>
#include "../include/resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
    InitWindow(300, 600, "raylib Tetris");
    SetTargetFPS(60);
    while(WindowShouldClose() == false) {
        BeginDrawing();
         
        EndDrawing();
    }
    CloseWindow();
}
