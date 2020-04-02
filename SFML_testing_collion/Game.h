#pragma once

#include <cmath>
#include "Player.h"

class Game
{
private:
	bool m_running;
	bool m_rKey;

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

