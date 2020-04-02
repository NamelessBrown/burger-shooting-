#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <limits>
#include <vector>

class Player
{
public:
	Player();

	const sf::FloatRect getBounds() const { return player.getGlobalBounds(); }
	const sf::RectangleShape getPlayer() const { return player; }
	const std::vector<sf::CircleShape> getBullets() const { return bullets; }

	void update();
	void render(sf::RenderTarget& target);
private:
	int m_armor;
	float m_speed;
	int m_attackDamage;
	int m_hp;
	bool m_spacePressed;
	int m_shots;
	bool m_canReload;
	bool m_hitTheRKey;
	unsigned m_maxBullets;

	sf::RectangleShape player;
	std::vector<sf::CircleShape> bullets;
	sf::Text m_text;
	sf::Font m_font;

	void movement();
	void bulletMovement();
};


