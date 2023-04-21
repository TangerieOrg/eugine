# pragma once
#include "raylib.h"
#include <emscripten/emscripten.h>
#include <emscripten/html5.h>
#include <iostream>


class Screen {
private:
    Vector2 size;

public:
    Screen(int width, int height);
    
    void Init();
    void Close();
    void SetSize(int width, int height);
    void OnResize();
};