#include "Player.h"

Player::Player()
	:m_armor(5), m_attackDamage(10), m_hp(100), m_speed(5.5f), m_spacePressed(false), m_shots(0), m_canReload(false), m_hitTheRKey(false)
{

	player.setFillColor(sf::Color::Yellow);
	player.setSize(sf::Vector2f(25.5f, 25.5f));
	player.setPosition(sf::Vector2f(250.f, 250.f));

	m_font.loadFromFile("timesnewroman.ttf");

	bullets.reserve(25);

	m_maxBullets = bullets.capacity();

	m_text.setFont(m_font);
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setCharacterSize(25);

}

void Player::reload(bool& hitkey)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && m_canReload && !hitkey)
	{
		bullets.clear();
	}
}

void Player::movement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		player.move(sf::Vector2f(-m_speed, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		player.move(sf::Vector2f(m_speed, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		player.move(sf::Vector2f(0.f, -m_speed));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		player.move(sf::Vector2f(0.f, m_speed));
	}

}

void Player::bulletMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !m_canReload)
	{
		m_shots++;
		player.setFillColor(sf::Color::Red);
		sf::CircleShape bullet;
		bullet.setFillColor(sf::Color::Red);
		bullet.setRadius(40);
		bullet.setOrigin(sf::Vector2f(bullet.getRadius() - bullet.getRadius(), 0.0f));
		bullet.setPosition(player.getPosition());
		bullets.push_back(bullet);
	}
	else
	{
		player.setFillColor(sf::Color::Yellow);
	}

	if (bullets.size() > m_maxBullets)
	{
		m_canReload = true;
		m_shots = 0;
	}
	else
	{
		m_canReload = false;
	}

	

}

void Player::update()
{
	movement();
	bulletMovement();

	std::stringstream ss;
	ss << "Armor = " << m_armor << '\n' << "Speed = " << m_speed << '\n' << "Attack Damage = " << m_attackDamage << '\n' << "Hp = " << m_hp << '\n'
		<< "Lazer beans you shot: " << m_shots << '\n' << "Lazer bean cap = " << m_maxBullets << '\n' << "Hit the R button for reload" << '\n';

	m_text.setString(ss.str());

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(m_text);

	for (auto& e : bullets)
	{
		while (e.getPosition().x < target.getSize().x)
		{
			e.move(sf::Vector2f(m_speed, 0.0f));
			target.draw(e);
		}
	}

	target.draw(player);

}
