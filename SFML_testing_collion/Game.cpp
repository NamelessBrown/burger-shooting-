#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "small game 01", sf::Style::Close);
	window->setFramerateLimit(60); 
	window->setVerticalSyncEnabled(true);
}

void Game::collion()
{
	for (unsigned x = 0; x < guys.size(); x++)
	{
		if (player.getBounds().contains(guys[x].getBadGuy().getPosition()))
		{
			guys.erase(guys.begin() + x);
		}
	}
}

Game::Game()
	:m_running(true), m_rKey(false)
{
	initWindow();
	guys.push_back(BadGuys());
	guys.push_back(BadGuys());
	guys.push_back(BadGuys());
	guys.push_back(BadGuys());
	guys.push_back(BadGuys());
}

Game::~Game()
{
	delete window;
}

void Game::pollEvent()
{
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
				player.reload(m_rKey);
			m_rKey = true;
			break;
		case sf::Event::KeyReleased:
			m_rKey = false;
			break;
		}
		
		
	}
}

void Game::update()
{
	pollEvent();
	player.update();

	for (unsigned x = 0; x < guys.size(); x++)
	{
		collion();
		if (guys.size() == 0)
		{
			guys.push_back(BadGuys());
		}
		else
		{
			guys[x].update(2.f, 0.0f);
		}
	}
}

void Game::render()
{
	window->clear();
	player.render(*window);

	for (unsigned x = 0; x < guys.size(); x++)
	{
		guys[x].render(*window);
	}

	window->display();
}
