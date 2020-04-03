#include "Game.h"

void Game::initWindow()
{
	window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "small game 01", sf::Style::Close);
	window->setFramerateLimit(60); 
	window->setVerticalSyncEnabled(true);
}

void Game::collion()
{
	for (unsigned i = 0; i < guys.size(); i++)
	{
		if (player.getBullet().getGlobalBounds().intersects(guys[i].getBounds())) //bullets hit the enemy
		{
			guys.erase(guys.begin() + i);
			guys.push_back(BadGuys());
		}
		else if (guys[i].getBadGuy().getPosition().x > window->getSize().x) //enemy goes off screen
		{
			guys.erase(guys.begin() + i);
			guys.push_back(BadGuys());
		}
	}
}

Game::Game()
	:m_running(true)
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
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
			{
				
			}
			break;
		case sf::Event::KeyReleased:
			break;
		}
		
		
	}
}

void Game::update()
{
	pollEvent();
	player.update();
	collion();

	for (unsigned x = 0; x < guys.size(); x++)
	{
		guys[x].update(2.f, 0.0f);
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
