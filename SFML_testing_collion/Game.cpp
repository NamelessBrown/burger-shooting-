#include "Game.h"

void Game::initWindow()
{
	m_window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Burger shooter", sf::Style::Close);
	m_window->setFramerateLimit(60); 
	m_window->setVerticalSyncEnabled(true);
}

void Game::collion()
{
	for (unsigned i = 0; i < m_guys.size(); i++)
	{
		if (m_player.getBullet().getGlobalBounds().intersects(m_guys[i]->getBounds())) //bullets hit the enemy
		{
			m_guys[i].reset();
			m_guys.erase(m_guys.begin() + i);
			m_guys.emplace_back(new BadGuys(m_badGuyTexture));
		}
		else if (m_guys[i]->getBadGuy().getPosition().x > m_window->getSize().x) //enemy goes off screen
		{
			m_guys[i].reset();
			m_guys.erase(m_guys.begin() + i);
			m_guys.emplace_back(new BadGuys(m_badGuyTexture));

			m_player.loseHp(m_guys[i]->getAttackDamage());

		}
	}
}

Game::Game()
	:m_running(true), m_guysSpawner(7)
{
	initWindow();
	m_badGuyTexture.loadFromFile("Textures/wieght.png");

	for (int i = 0; i < m_guysSpawner; i++)
	{
		m_guys.emplace_back(new BadGuys(m_badGuyTexture));
	}
}

Game::~Game()
{
	for (auto& e : m_guys)
	{
		e.reset();
	}

	m_guys.clear();

	delete m_window;
}

void Game::pollEvent()
{
	m_deltaTime = m_clock.restart().asSeconds() * 60.f;

	while (m_window->pollEvent(m_event))
	{
		switch (m_event.type)
		{
		case sf::Event::Closed:
			m_window->close();
			break;
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
			{
				m_window->close();
			}
			break;
		}
		
		
	}
}

void Game::update()
{
	pollEvent();
	m_player.update(m_deltaTime);
	collion();

	for (unsigned x = 0; x < m_guys.size(); x++)
	{
		m_guys[x]->update(1.f, 0.0f, m_deltaTime);
	}

	if (m_music.getSong().getStatus() == sf::Music::Stopped)
	{
		m_music.Play();
	}
}

void Game::render()
{
	m_window->clear();
	m_player.render(*m_window);

	for (unsigned x = 0; x < m_guys.size(); x++)
	{
		m_guys[x]->render(*m_window);
	}

	m_window->display();
}
