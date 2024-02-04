#pragma once
#include "Utils.h"


#define TITLE "Space Sentinel"

class Game
{
public:

	Game(const Vector2& resolution);

	void Run();

private:

	Vector2 res;
};