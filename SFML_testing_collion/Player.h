#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <limits>
#include <vector>

class Player
{
public:
	Player();

	const sf::FloatRect getBounds() const { return m_player.getGlobalBounds(); }
	const sf::RectangleShape getPlayer() const { return m_player; }
	const sf::RectangleShape getBullet() const { return m_bullet; }

	void update();
	void render(sf::RenderTarget& target);
private:
	int m_armor;
	float m_speed;
	float m_bulletSpeed;
	int m_attackDamage;
	int m_hp;
	int m_shots;
	bool m_canReload;

	sf::RectangleShape m_player;
	sf::RectangleShape m_bullet;
	sf::Text m_text;
	sf::Font m_font;

	void movement();
	void bulletMovement();
};


