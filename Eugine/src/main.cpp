#include <iostream>
#include <string> 
#include "raylib.h"

#include <emscripten/emscripten.h>
#include <emscripten/html5.h>

#include "Utils/screen.hpp"
#include "game.hpp"

#include "tokens.hpp"

#define PLATFORM_WEB

void UpdateDrawFrame(void);

Screen screen(0, 0);
Game game;

void NullLogger(int msgType, const char *text, va_list args) {}

int main(void) {
    SetTraceLogCallback(NullLogger);
    screen.Init();
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);

    screen.Close();
    return 0;
}

void UpdateDrawFrame(void) {
    BeginDrawing();

    ClearBackground(Color{0, 0, 0, 255});
    
    game.OnUpdate();

    auto fpsStr = std::to_string(GetFPS());
    DrawText(fpsStr.c_str(), 0, 0, 30, RAYWHITE);

    EndDrawing();
}