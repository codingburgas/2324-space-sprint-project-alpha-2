#include "planets.h"
#include <cmath>

Planets::Planets() {
    planets[0] = { 143, 185, 7 };  // Mercury
    planets[1] = { 187, 185, 11 }; // Venus
    planets[2] = { 238, 186, 13 }; // Earth
    planets[3] = { 282, 186, 5 };  // Mars
    planets[4] = { 344, 186, 30 }; // Jupiter
    planets[5] = { 439, 185, 21 }; // Saturn
    planets[6] = { 511, 185, 18 }; // Uranus
    planets[7] = { 574, 184, 14 }; // Neptune
}



Planets::~Planets() {
    // Destructor if needed
}

void Planets::DrawPlanets() {
}

int Planets::CheckCollisionPlanet(Vector2 mousePos) {
    for (int i = 0; i < 8; i++) {
        float distance = sqrt(pow(mousePos.x - planets[i].x, 2) + pow(mousePos.y - planets[i].y, 2));
        if (distance < planets[i].r) {
            return i;
        }
    }
    return -1;
}