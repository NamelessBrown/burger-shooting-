#pragma once

#include <cmath>
#include <memory>
#include "Player.h"
#include "BadGuys.h"
#include "Music.h"

class Game
{
public:
	Game();
	virtual ~Game();

	const bool running() const { return m_window->isOpen(); }
	const bool GameOver() const { return m_player.getHp() > 0; }

	void pollEvent();
	void update();
	void render();

private:
	bool m_running;
	int m_guysSpawner;
	float m_deltaTime;

	sf::RenderWindow* m_window;
	sf::Event m_event;
	sf::Clock m_clock;
	sf::Texture m_badGuyTexture;

	Player m_player;
	std::vector<std::unique_ptr<BadGuys>> m_guys;
	Music m_music;

	void initWindow();
	void collion();
};

