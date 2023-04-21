#include "Utils/screen.hpp"



EM_JS(int, body_get_width, (), {
    return document.body.clientWidth;
});

EM_JS(int, body_get_height, (), {
    return document.body.clientHeight;
});

EM_BOOL handleResize(int eventType, const EmscriptenUiEvent* uiEvent, void* userData) {
    auto screen = (Screen *)userData;
    screen->OnResize();
    return EM_TRUE;
}

void Screen::OnResize() {
    this->SetSize(body_get_width(), body_get_height());
}

Screen::Screen(int width, int height) {
    this->SetSize(width, height);
}

void Screen::Init() {
    InitWindow(size.x, size.y, "");
    emscripten_set_resize_callback(EMSCRIPTEN_EVENT_TARGET_WINDOW, this, true, handleResize);
}

void Screen::Close() {
    CloseWindow();
}

void Screen::SetSize(int width, int height) {
    if(width == 0) width = body_get_width();
    if(height == 0) height = body_get_height();

    size.x = width;
    size.y = height;
    SetWindowSize(size.x, size.y);
}