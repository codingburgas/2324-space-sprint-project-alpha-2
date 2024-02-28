#include <raylib.h>
#include "game.h"
#include "Planets.h"
#include <iostream>

typedef GameState MenuState;

Texture2D LoadBackground(const char* filename) {
    Texture2D background = LoadTexture(filename);
    return background;
}

int main() {
    const int screenWidth = 640;
    const int screenHeight = 360;

    InitWindow(screenWidth, screenHeight, "Space Sentinel");

    MenuState currentState = MAIN_MENU;

    Planets planets;

    // Load initial background
    Texture2D background1 = LoadTexture("assets/solarSystem.png");
    Texture2D background2 = LoadTexture("assets/Planets/venusSurface.png");
    Texture2D currentBackground = background1; // Start with background1

    // Keep track of the last direction the monkey moved to
    enum Direction {
        NONE,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Direction lastDirection = NONE;

    Font font = LoadFont("SpaceSentinel/fonts/Audiowide-Regular.ttf");

    MenuState planetNames[8] = { MERCURY, VENUS, EARTH, MARS, JUPITER, SATURN, URANUS, NEPTUNE };
    while (!WindowShouldClose()) {
        // Main menu
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            int collidedPlanet = planets.CheckCollisionPlanet(GetMousePosition());
            if (collidedPlanet != -1) {
                switch (collidedPlanet) {
                case 0:
                    currentState = planetNames[0];
                    break;
                case 1:
                    currentState = planetNames[1];
                    break;
                case 2:
                    currentState = planetNames[2];
                    break;
                case 3:
                    currentState = planetNames[3];
                    break;
                case 4:
                    currentState = planetNames[4];
                    break;
                case 5:
                    currentState = planetNames[5];
                    break;
                case 6:
                    currentState = planetNames[6];
                    break;
                case 7:
                    currentState = planetNames[7];
                    break;
                default:
                    // Handle error
                    break;
                }
            }
        }


        if (currentState == MAIN_MENU) {
            // Draw main menu

            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(currentBackground, 0, 0, WHITE);

            // Draw planets
            planets.DrawPlanets();


            DrawTextEx(font, "Space Sentinel", Vector2(screenWidth / 2 - MeasureTextEx(font, "Space Sentinel", 40, 1).x / 2, screenHeight / 20), 40, 1, RAYWHITE);
            DrawText("Press 'Q' to Quit", screenWidth / 2 + 10 - MeasureText("Press 'Q' to Quit", 20) / 2, screenHeight / 2 + 100, 20, RAYWHITE);

            EndDrawing();

            // Check for menu actions
            if (IsKeyPressed(KEY_Q)) {
                break; // Quit game
            }
        }
        // Gameplay
        else if (currentState != MAIN_MENU) {
            Game game;
            game.Run(currentState);

            // Update the direction the monkey is facing based on the last direction moved
            if (IsKeyDown(KEY_A)) {
                lastDirection = LEFT;
            }
            else if (IsKeyDown(KEY_D)) {
                lastDirection = RIGHT;
            }
            else if (IsKeyDown(KEY_W)) {
                lastDirection = UP;
            }
            else if (IsKeyDown(KEY_S)) {
                lastDirection = DOWN;
            }

            currentState = MAIN_MENU; // Return to main menu after gameplay
        }


    }

    CloseWindow();

    return 0;
}