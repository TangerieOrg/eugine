#include <iostream>

#include "raylib.h"

#include <emscripten/emscripten.h>

const int screenWidth = 800;
const int screenHeight = 450;

void UpdateDrawFrame(void);

int main(void) {
    InitWindow(screenWidth, screenHeight, "Basic Window");

    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);

    CloseWindow();

    return 0;
}

void UpdateDrawFrame(void) {
    BeginDrawing();

    ClearBackground(Color{0, 0, 0, 255});
    DrawText("Hello World", 190, 200, 20, RAYWHITE);

    EndDrawing();
}