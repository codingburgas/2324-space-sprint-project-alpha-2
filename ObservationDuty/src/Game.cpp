#include "Game.h"


Game::Game(const Vector2& resolution)
	: res(resolution)
{
	SetTargetFPS(60);
	InitWindow(res.x, res.y, TITLE);
}


void Game::Run()
{

	Font font;

	font = LoadFont("ObservationDuty/fonts/Audiowide-Regular.ttf");



	while (!WindowShouldClose())
	{
		BeginDrawing();

		DrawTextSCentered(font, TITLE, Vector2(50, 7), 64, RAYWHITE);

		EndDrawing();
	}
	CloseWindow();
}