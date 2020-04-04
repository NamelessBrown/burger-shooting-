#include "Player.h"

Player::Player()
	:m_armor(5), m_attackDamage(10), m_hp(100), m_speed(5.5f), m_shots(0), m_canReload(false), m_bulletSpeed(25.5f)
{
	m_notShootingTexture.loadFromFile("Textures/bigboy.jpg");
	m_shootingTexture.loadFromFile("Textures/smile.png");
	m_bulletTexture.loadFromFile("Textures/br.jpg");

	m_player.setTexture(m_notShootingTexture);
	m_player.setScale(m_player.getScale() / 6.f);
	m_player.setPosition(sf::Vector2f(0.f, 250.f));

	m_bullet.setTexture(m_bulletTexture);
	m_bullet.setScale(m_bullet.getScale() / 14.f);
	m_bullet.setPosition(m_player.getPosition());
	//bullet.setScale(bullet.getScale() / 4.f);
	//bullet.setPosition(player.getPosition());

	m_font.loadFromFile("timesnewroman.ttf");

	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setCharacterSize(25);

}

void Player::movement(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_player.move(sf::Vector2f(0.f, -m_speed * deltaTime));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_player.move(sf::Vector2f(0.f, m_speed * deltaTime));
	}

}

void Player::bulletMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_canReload)
	{
		m_shots++;
		m_player.setTexture(m_shootingTexture);
		m_bullet.setPosition(m_player.getPosition());
	}
	else
	{
		m_player.setTexture(m_notShootingTexture);
	}

	if (m_bullet.getPosition().x > 1000.f)
	{
		m_canReload = false;
	}
	else
	{
		m_player.setTexture(m_shootingTexture);
		m_canReload = true;
	}

}

void Player::update(float deltaTime)
{
	movement(deltaTime);
	bulletMovement();

	std::stringstream ss;
	ss << "Armor = " << m_armor << '\n' << "Speed = " << m_speed << '\n' << "Attack Damage = " << m_attackDamage << '\n' << "Hp = " << m_hp << '\n'
		<< "burgers you shot: " << m_shots << '\n';

	m_text.setString(ss.str());

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(m_text);

	if (m_bullet.getPosition().x < target.getSize().x) //laser effect
	{
		m_bullet.move(sf::Vector2f(m_bulletSpeed, 0.0f));
		target.draw(m_bullet);
	} 

	target.draw(m_player);

}
