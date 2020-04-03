#include "Game.h"

void Game::initWindow()
{
	m_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "small game 01", sf::Style::Close);
	m_window->setFramerateLimit(60); 
	m_window->setVerticalSyncEnabled(true);
}

void Game::collion()
{
	for (unsigned i = 0; i < m_guys.size(); i++)
	{
		if (m_player.getBullet().getGlobalBounds().intersects(m_guys[i].getBounds())) //bullets hit the enemy
		{
			m_guys.erase(m_guys.begin() + i);
			m_guys.push_back(BadGuys());
		}
		else if (m_guys[i].getBadGuy().getPosition().x > m_window->getSize().x) //enemy goes off screen
		{
			m_guys.erase(m_guys.begin() + i);
			m_guys.push_back(BadGuys());
		}
	}
}

Game::Game()
	:m_running(true), m_guysSpawner(7)
{
	initWindow();

	for (int i = 0; i < m_guysSpawner; i++)
	{
		m_guys.push_back(BadGuys());
	}
}

Game::~Game()
{
	delete m_window;
}

void Game::pollEvent()
{
	while (m_window->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window->close();
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
	m_player.update();
	collion();

	for (unsigned x = 0; x < m_guys.size(); x++)
	{
		m_guys[x].update(2.f, 0.0f);
	}
}

void Game::render()
{
	m_window->clear();
	m_player.render(*m_window);

	for (unsigned x = 0; x < m_guys.size(); x++)
	{
		m_guys[x].render(*m_window);
	}

	m_window->display();
}
