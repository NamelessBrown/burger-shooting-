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
	const sf::RectangleShape getBullet() const { return bullet; }

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

	sf::RectangleShape player;
	sf::RectangleShape bullet;
	sf::Text m_text;
	sf::Font m_font;

	void movement();
	void bulletMovement();
};


