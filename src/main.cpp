#include <raylib.h>
#include "game.h"

double lastTimeUpdate = 0;

bool EventTriggered(double interval) {
    double currentTime = GetTime();
    if(currentTime - lastTimeUpdate >= interval) {
        lastTimeUpdate = currentTime;
        return true;
    }
    return false;
}
int main()
{
    Color darkBlue = {44, 44, 127, 255};
    InitWindow(300, 600, "raylib  Tetris");
    SetTargetFPS(60);
    Game game = Game();
    while(WindowShouldClose() == false) {
        game.HandleInput();
        if(EventTriggered(0.2)) {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}