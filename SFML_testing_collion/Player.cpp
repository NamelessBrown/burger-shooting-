#include "Player.h"

Player::Player()
	:m_armor(5), m_attackDamage(10), m_hp(100), m_speed(5.5f), m_shots(0), m_canReload(false), m_bulletSpeed(25.5f)
{

	player.setFillColor(sf::Color::Yellow);
	player.setSize(sf::Vector2f(25.5f, 25.5f));
	player.setPosition(sf::Vector2f(0.f, 250.f));

	bullet.setFillColor(sf::Color::Red);
	bullet.setSize(player.getSize() / 2.f);
	bullet.setPosition(player.getPosition());
	//bullet.setScale(bullet.getScale() / 4.f);
	//bullet.setPosition(player.getPosition());

	m_font.loadFromFile("timesnewroman.ttf");

	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setCharacterSize(25);

}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.move(sf::Vector2f(0.f, -m_speed));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.move(sf::Vector2f(0.f, m_speed));
	}

}

void Player::bulletMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_canReload)
	{
		m_shots++;
		player.setFillColor(sf::Color::Blue);
		bullet.setPosition(player.getPosition());
	}
	else
	{
		player.setFillColor(sf::Color::Yellow);
	}

	if (bullet.getPosition().x > 1000.f)
	{
		m_canReload = false;
	}
	else
	{
		m_canReload = true;
	}

}

void Player::update()
{
	movement();
	bulletMovement();

	std::stringstream ss;
	ss << "Armor = " << m_armor << '\n' << "Speed = " << m_speed << '\n' << "Attack Damage = " << m_attackDamage << '\n' << "Hp = " << m_hp << '\n'
		<< "Lazer beans you shot: " << m_shots << '\n';

	m_text.setString(ss.str());

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(m_text);

	if (bullet.getPosition().x < target.getSize().x) //laser effect
	{
		bullet.move(sf::Vector2f(m_bulletSpeed, 0.0f));
		target.draw(bullet);
	} 

	target.draw(player);

}
