#include "BadGuys.h"
#include <random>

void BadGuys::movement(float x, float y)
{
	m_guys.move(x, y);
}

BadGuys::BadGuys()
	:m_speed(1.f)
{
	std::random_device rd;
	std::mt19937 rng(rd());
	std::uniform_real_distribution<float> distrubutionX(25.f, 125.f);
	std::uniform_real_distribution<float> distrubutionY(100.f, 750.f);

	m_guyTexture.loadFromFile("Textures/wieght.png");
	m_guys.setTexture(m_guyTexture);
	m_guys.setScale(m_guys.getScale() / 14.f);
	m_guys.setPosition(sf::Vector2f(distrubutionX(rng), distrubutionY(rng)));
}

BadGuys::~BadGuys()
{
}

void BadGuys::update(float x, float y, float deltaTime)
{
	movement(x * deltaTime + m_speed, y * deltaTime);
}

void BadGuys::render(sf::RenderTarget& target)
{
	target.draw(m_guys);
}