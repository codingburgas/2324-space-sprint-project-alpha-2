#include "game.h"
#include <iostream>

Game::Game() {

    const int screenWidth = 640;
    const int screenHeight = 360;

    InitTextures();
    currentFrame = 0;
    isMovingLeft = false;
    isMovingRight = false;
    isMovingUp = false;
    isMovingDown = false;
    updateTime = 0.7f; // Adjust as needed for animation speed
    monkeyPosition = { screenWidth / 2.0f, screenHeight / 2.0f };
    drawCharacter = true; // Initially, draw the character

    SetTargetFPS(60);
}

Game::~Game() {
    UnloadTextures();
    UnloadTextures();
}

void Game::Run(GameState& gameState) {
    state = gameState;
    InitTextures();

    while (!WindowShouldClose()) {
        Update();
        Draw();
    }

    UnloadTextures();
}

void Game::InitTextures() {

    monkeyLeftFrames[0] = LoadTexture("assets/Monkey/monkeySideLeft.png");
    monkeyLeftFrames[1] = LoadTexture("assets/Monkey/monkeySideLeftRun1.png");
    monkeyLeftFrames[2] = LoadTexture("assets/Monkey/monkeySideLeftRun2.png");

    monkeyRightFrames[0] = LoadTexture("assets/Monkey/monkeySideRight.png");
    monkeyRightFrames[1] = LoadTexture("assets/Monkey/monkeySideRightRun1.png");
    monkeyRightFrames[2] = LoadTexture("assets/Monkey/monkeySideRightRun2.png");

    monkeyUpFrames[0] = LoadTexture("assets/Monkey/monkeyBack.png");
    monkeyUpFrames[1] = LoadTexture("assets/Monkey/monkeyBackRun1.png");
    monkeyUpFrames[2] = LoadTexture("assets/Monkey/monkeyBackRun2.png");

    monkeyDownFrames[0] = LoadTexture("assets/Monkey/monkeyFront.png");
    monkeyDownFrames[1] = LoadTexture("assets/Monkey/monkeyFrontRunLeft.png");
    monkeyDownFrames[2] = LoadTexture("assets/Monkey/monkeyFrontRunRight.png");

    planetTextures[MERCURY] = LoadTexture("assets/Planets/Mercury.png");
    planetTextures[VENUS] = LoadTexture("assets/Planets/Venus.png");
    planetTextures[EARTH] = LoadTexture("assets/Planets/Earth.png");
    planetTextures[MARS] = LoadTexture("assets/Planets/Mars.png");
    planetTextures[JUPITER] = LoadTexture("assets/Planets/Jupiter.png");
    planetTextures[SATURN] = LoadTexture("assets/Planets/Saturn.png");
    planetTextures[URANUS] = LoadTexture("assets/Planets/Uranus.png");
    planetTextures[NEPTUNE] = LoadTexture("assets/Planets/Neptune.png");

}


void Game::UnloadTextures() {
    for (int i = 0; i < FRAME_COUNT; ++i) {
        UnloadTexture(monkeyLeftFrames[i]);
        UnloadTexture(monkeyRightFrames[i]);
        UnloadTexture(monkeyUpFrames[i]);
        UnloadTexture(monkeyDownFrames[i]); 
    }

    for (int i = 0; i < 8; ++i)
    {
        UnloadTexture(planetTextures[i]);
    }
}

void Game::Update() {

    if (IsKeyDown(KEY_A)) {
        isMovingLeft = true;
        isMovingRight = false;
        isMovingUp = false;
        isMovingDown = false;
    }
    else if (IsKeyDown(KEY_D)) {
        isMovingLeft = false;
        isMovingRight = true;
        isMovingUp = false;
        isMovingDown = false;
    }
    else if (IsKeyDown(KEY_W)) {
        isMovingLeft = false;
        isMovingRight = false;
        isMovingUp = true;
        isMovingDown = false;
    }
    else if (IsKeyDown(KEY_S)) {
        isMovingLeft = false;
        isMovingRight = false;
        isMovingUp = false;
        isMovingDown = true;
    }
    else {
        isMovingLeft = false;
        isMovingRight = false;
        isMovingUp = false;
        isMovingDown = false;
        currentFrame = 0; // Reset to still frame
    }

    if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
    {
        isMovingUp = true;
        isMovingDown = false;
        isMovingLeft = false;
        isMovingRight = true;
    }
    else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_A))
    {
        isMovingUp = true;
        isMovingDown = false;
        isMovingLeft = true;
        isMovingRight = false;
    }
    else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
    {
        isMovingUp = false;
        isMovingDown = true;
        isMovingLeft = false;
        isMovingRight = true;
    }
    else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_A))
    {
        isMovingUp = false;
        isMovingDown = true;
        isMovingLeft = true;
        isMovingRight = false;
    }
    else if (IsKeyDown(KEY_W) && IsKeyDown(KEY_S))
    {
        isMovingUp = false;
        isMovingDown = false;
        isMovingLeft = false;
        isMovingRight = false;
    }
    else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_D))
    {
        isMovingUp = false;
        isMovingDown = false;
        isMovingLeft = false;
        isMovingRight = false;
    }

    // Update animation only if moving
    if (isMovingLeft || isMovingRight || isMovingUp || isMovingDown) {
        // Update frame based on current frame count
        updateTime -= GetFrameTime();
        if (updateTime <= 0) {
            currentFrame = (currentFrame + 1) % FRAME_COUNT;
            updateTime = 0.1f; // Reset animation speed
        }
    }


    // Update position based on movement keys
    if (isMovingLeft) monkeyPosition.x -= 3;
    if (monkeyPosition.x < 0) monkeyPosition.x = GetScreenWidth() - monkeyRightFrames->width + 30;
    if (isMovingRight) monkeyPosition.x += 3;
    if (monkeyPosition.x > GetScreenWidth() - monkeyRightFrames->width + 30) monkeyPosition.x = 0;
    if (isMovingUp) monkeyPosition.y -= 3;
    if (monkeyPosition.y < 0) monkeyPosition.y = GetScreenHeight() - monkeyUpFrames->height + 30;
    if (isMovingDown) monkeyPosition.y += 3;
    if (monkeyPosition.y > GetScreenHeight() - monkeyUpFrames->height + 30) monkeyPosition.y = 0;

}
void Game::Draw() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    switch (state)
    {
    case MAIN_MENU:
        DrawTexture(mainMenuTexture, 0, 0, WHITE);
        break;
    default:
        DrawTexture(planetTextures[state], 0, 0, WHITE);
    }


    // Draw current frame of monkey animation based on direction
    if (drawCharacter) {
        if (isMovingLeft) {
            DrawTexture(monkeyLeftFrames[currentFrame], monkeyPosition.x, monkeyPosition.y, WHITE);
        }
        else if (isMovingRight) {
            DrawTexture(monkeyRightFrames[currentFrame], monkeyPosition.x, monkeyPosition.y, WHITE);
        }
        else if (isMovingUp) {
            DrawTexture(monkeyUpFrames[currentFrame], monkeyPosition.x, monkeyPosition.y, WHITE);
        }
        else if (isMovingDown) {
            DrawTexture(monkeyDownFrames[currentFrame], monkeyPosition.x, monkeyPosition.y, WHITE);
        }
        else {
            // If the monkey is not moving, face the last direction moved
            DrawTexture(monkeyDownFrames[0], monkeyPosition.x, monkeyPosition.y, WHITE);
        }

        EndDrawing();
    }
}
