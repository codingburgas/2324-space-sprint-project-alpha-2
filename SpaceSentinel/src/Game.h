#pragma once
#include <raylib.h>
#include <vector>
#include "Stars.h" // Include Star.h


#define TITLE "Space Sentinel"

class Game {
public:
    Game(const Vector2& resolution);
    void Run();

private:
    Vector2 res;
    std::vector<Star> stars; // Declare stars vector as a member variable
};
