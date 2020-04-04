#pragma once

#include <cmath>
#include "Player.h"
#include "BadGuys.h"

class Game
{
public:
	Game();
	virtual ~Game();

	const bool running() const { return m_running; }

	void pollEvent();
	void update();
	void render();

private:
	bool m_running;
	int m_guysSpawner;

	sf::RenderWindow* m_window;
	sf::Event m_event;

	Player m_player;
	std::vector<BadGuys*> m_guys;

	void initWindow();
	void collion();
};

