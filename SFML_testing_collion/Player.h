#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <limits>
#include <iostream>
#include <vector>
#include <random>

class Player
{
public:
	Player();

	void reload(bool& hitkey);

	const sf::FloatRect getBounds() const { return player.getGlobalBounds(); }
	const sf::RectangleShape getPlayer() const { return player; }

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

class BadGuys
{
public:
	BadGuys();

	void shoot();


	void update(float x, float y);
	void render(sf::RenderTarget& target);

	const sf::FloatRect getBounds() const { return guys.getGlobalBounds(); }
	const sf::RectangleShape getBadGuy() const { return guys; }
private:
	float m_speed;
	int m_attackDamage;
	int m_hp;
	unsigned m_shots;
	unsigned m_maxBullets;

	sf::RectangleShape guys;
	std::vector<sf::CircleShape> bullets;

	void movement(float x, float y);
};

