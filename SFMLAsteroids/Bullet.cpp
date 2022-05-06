#include "Bullet.h"

#include <iostream>

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f startPosition)
{
	texture.loadFromFile("Resources/Bullet.png");
	sprite.setTexture(texture);


	int x = sprite.getLocalBounds().width / 2;
	int y = sprite.getLocalBounds().height / 2;
	sprite.setOrigin(sf::Vector2f(x, y));

	sprite.setPosition(startPosition);

	this->direction = direction;
	speed = 1000.0f;

	timeAlive = 5;

	bullets.push_back(this);
}

void Bullet::MoveBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->timeAlive -= General::GetDeltaTime();
		if (bullets[i]->timeAlive <= 0)
		{
			delete bullets[i];
			bullets[i] = nullptr;
			bullets.erase(bullets.begin() + i);
		}
		else
		{
			General::window.draw(bullets[i]->sprite);
			bullets[i]->sprite.move(bullets[i]->direction * bullets[i]->speed * General::GetDeltaTime());
		}
	}
}
