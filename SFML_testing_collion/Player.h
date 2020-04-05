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
	const sf::Sprite getPlayer() const { return m_player; }
	const sf::Sprite getBullet() const { return m_bullet; }

	const int getArmor() const { return m_armor; }
	const int getHp() const { return m_hp; }

	const void loseHp(int loss) { m_hp -= loss; }

	void update(float deltaTime);
	void render(sf::RenderTarget& target);
private:
	int m_armor;
	float m_speed;
	float m_bulletSpeed;
	int m_hp;
	int m_shots;
	bool m_canReload;

	sf::Texture m_bulletTexture;
	sf::Texture m_notShootingTexture;
	sf::Texture m_shootingTexture;
	sf::Sprite m_player;
	sf::Sprite m_bullet;
	sf::Text m_text;
	sf::Font m_font;

	void movement(float deltaTime);
	void bulletMovement();
};


