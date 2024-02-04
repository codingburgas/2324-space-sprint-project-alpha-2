#include "Game.h"
#include "Button.h"

int main()
{

	Game* game = new Game(Vector2(1280, 720));
	game->Run();

	


	delete game;
}