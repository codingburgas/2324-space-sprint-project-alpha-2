#include "Game.h"
#include "Stars.h"
#include "Utils.h"
#include <raylib.h>

Game::Game(const Vector2& resolution)
    : res(resolution)
{
    SetTargetFPS(60);
    InitWindow(res.x, res.y, TITLE);

    // Create some initial stars
    for (int i = 0; i < 100; ++i) {
        Vector2 starPos = { GetRandomValue(0, res.x), GetRandomValue(0, res.y) };
        stars.emplace_back(starPos); // Emplace back Star objects
    }
}

void Game::Run()
{
    SetWindowState(FLAG_FULLSCREEN_MODE);

    Font font;
    Texture2D button1;
    Texture2D background = LoadTexture("SpaceSentinel/images/MainMenuBackground.png");

    button1 = LoadTexture("SpaceSentinel/Images/Button.png");

    font = LoadFont("SpaceSentinel/fonts/Audiowide-Regular.ttf");

    int buttonPosX = (res.x - button1.width) / 2;

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        // Update star positions
        for (auto& star : stars) {
            star.Update(); // Call Update method of Star
        }

        // Draw stars
        for (const auto& star : stars) {
            star.Draw(); // Call Draw method of Star
        }

        DrawTextSCentered(font, TITLE, Vector2{ 50, 10 }, 64, RAYWHITE);

        EndDrawing();
    }

    UnloadTexture(background);
    CloseWindow();
}