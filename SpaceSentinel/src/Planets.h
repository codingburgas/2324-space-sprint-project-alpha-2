#pragma once
#include "raylib.h"

struct Planet {
    int x;
    int y;
    int r;
};

class Planets {
public:
    Planets();
    ~Planets();

    void DrawPlanets();
    int CheckCollisionPlanet(Vector2 point);

private:
    Planet planets[8];

    bool CheckCollisionCirclePoint(Vector2 center, float radius, Vector2 point);
};