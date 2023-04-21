#include "game.hpp"

void Game::OnUpdate() {
    auto mousePos = GetMousePosition();

    DrawLine(mousePos.x, 0, mousePos.x, GetScreenHeight(), GREEN);
    DrawLine(0, mousePos.y, GetScreenWidth(), mousePos.y, GREEN);
}