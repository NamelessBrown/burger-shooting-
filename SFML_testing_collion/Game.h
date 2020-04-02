#pragma once

#include <cmath>
#include "Player.h"
#include "BadGuys.h"

class Game
{
private:
	bool m_running;

	sf::RenderWindow* window;
	sf::Event event;

	Player player;
	std::vector<BadGuys> guys;

	void initWindow();
	void collion();
public:
	Game();
	virtual ~Game();

	const bool running() const { return m_running; }

	void pollEvent();
	void update();
	void render();

};

