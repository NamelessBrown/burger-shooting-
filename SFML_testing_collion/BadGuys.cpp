#include "BadGuys.h"
#include <random>

void BadGuys::movement(float x, float y)
{
	m_guys.move(x, y);
}

BadGuys::BadGuys()
	:m_speed(2.5f), m_attackDamage(20), m_hp(100)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distrubution(100.f, 250.f);

	m_guys.setFillColor(sf::Color::Green);
	m_guys.setSize(sf::Vector2f(25.5f, 25.5f));
	m_guys.setPosition(sf::Vector2f(distrubution(rng), distrubution(rng)));
}

void BadGuys::update(float x, float y)
{
	movement(x, y);
}

void BadGuys::render(sf::RenderTarget& target)
{
	target.draw(m_guys);
}