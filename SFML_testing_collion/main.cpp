// SFML_template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game.h"

int main()
{
	Game game;

	while (game.running() && game.GameOver())
	{
		game.update();
		game.render();
	}

}

