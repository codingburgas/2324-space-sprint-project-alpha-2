#include "Stars.h"
#include <raylib.h>

Star::Star(const Vector2& position) : position(position) {}

void Star::Update() {
    position.y -= 1; // Move upwards
    // Wrap around the screen
    if (position.x < 0) position.x = GetScreenWidth();
    if (position.x > GetScreenWidth()) position.x = 0;
    if (position.y < 0) position.y = GetScreenHeight();
    if (position.y > GetScreenHeight()) position.y = 0;
}

void Star::Draw() const {
    DrawPixel(static_cast<int>(position.x), static_cast<int>(position.y), WHITE);
}
