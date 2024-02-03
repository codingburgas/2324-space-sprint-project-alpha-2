#pragma once
#include "Utils.h"


#define TITLE "Observation Duty"

class Game
{
public:

	Game(const Vector2& resolution);

	void Run();

private:

	Vector2 res;
};