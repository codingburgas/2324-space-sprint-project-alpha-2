#include "raylib.h"

#define FRAME_COUNT 3 // Total frames for left/right movement

enum GameState
{
    MAIN_MENU = -1,
    MERCURY,
    VENUS,
    EARTH,
    MARS,
    JUPITER, SATURN, URANUS, NEPTUNE
};


class Game {
public:
    Game();
    ~Game();

    void Run(GameState& gameState);

private:
    Texture2D mainMenuTexture; // Background texture
    Texture2D planetTextures[8];
    Texture2D monkeyLeftFrames[FRAME_COUNT];
    Texture2D monkeyRightFrames[FRAME_COUNT];
    Texture2D monkeyUpFrames[FRAME_COUNT];
    Texture2D monkeyDownFrames[FRAME_COUNT];

    int currentFrame;
    bool isMovingLeft;
    bool isMovingRight;
    bool isMovingUp;
    bool isMovingDown;
    float updateTime;
    Vector2 monkeyPosition;
    bool drawCharacter; // Flag to control whether to draw the character
    bool characterVisible; // Variable to track the visibility of the character
    GameState state = MAIN_MENU;

    enum Direction {
        NONE,
        LEFT,
        RIGHT,
        UP,
        DOWN
    };
    Direction lastDirectionMoved;

    void InitTextures();
    void UnloadTextures();
    void Update();
    void Draw();
};