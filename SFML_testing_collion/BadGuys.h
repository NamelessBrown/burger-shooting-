#pragma once

#include <SFML/Graphics.hpp>

class BadGuys
{
public:
	BadGuys();

	void update(float x, float y);
	void render(sf::RenderTarget& target);

	const sf::FloatRect getBounds() const { return m_guys.getGlobalBounds(); }
	const sf::RectangleShape getBadGuy() const { return m_guys; }
private:
	float m_speed;
	int m_attackDamage;
	int m_hp;

	sf::RectangleShape m_guys;

	void movement(float x, float y);
};

