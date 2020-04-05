#pragma once

#include <SFML/Graphics.hpp>

class BadGuys
{
public:
	BadGuys();
	~BadGuys();

	void update(float x, float y, float deltaTime);
	void render(sf::RenderTarget& target);

	const sf::FloatRect getBounds() const { return m_guys.getGlobalBounds(); }
	const sf::Sprite getBadGuy() const { return m_guys; }

private:
	float m_speed;

	sf::Texture m_guyTexture;
	sf::Sprite m_guys;

	void movement(float x, float y);
};

