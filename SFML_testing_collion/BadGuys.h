#pragma once

#include <SFML/Graphics.hpp>

class BadGuys
{
public:
	BadGuys(sf::Texture& guy);
	~BadGuys();

	void update(float x, float y, float deltaTime);
	void render(sf::RenderTarget& target);

	const int getAttackDamage() const { return m_attackDamage; }
	const sf::FloatRect getBounds() const { return m_guys.getGlobalBounds(); }
	const sf::Sprite getBadGuy() const { return m_guys; }

private:
	float m_speed;
	int m_attackDamage;

	sf::Texture& m_guyTexture;
	sf::Sprite m_guys;

	void movement(float x, float y);
};

