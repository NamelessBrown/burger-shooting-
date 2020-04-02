#pragma once

#include <SFML/Graphics.hpp>

class BadGuys
{
public:
	BadGuys();

	void update(float x, float y);
	void render(sf::RenderTarget& target);

	const sf::FloatRect getBounds() const { return guys.getGlobalBounds(); }
	const sf::RectangleShape getBadGuy() const { return guys; }
private:
	float m_speed;
	int m_attackDamage;
	int m_hp;

	sf::RectangleShape guys;

	void movement(float x, float y);
};

