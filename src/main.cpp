#include <iostream>

#include "raylib.h"

#include <emscripten/emscripten.h>

const int screenWidth = 1920;
const int screenHeight = 1080;

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

    auto mousePos = GetMousePosition();

    DrawLine(mousePos.x, 0, mousePos.x, screenHeight, RED);
    DrawLine(0, mousePos.y, screenWidth, mousePos.y, RED);
    DrawText("Hello World", screenWidth / 2 - MeasureText("Hello World", 30) / 2, screenHeight / 2 - 15, 30, RAYWHITE);

    EndDrawing();
}