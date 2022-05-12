#include "Bullet.h"

#include <iostream>

void Bullet::DeleteBullet(int index)
{
	delete bullets[index];
	bullets[index] = nullptr;
	bullets.erase(bullets.begin() + index);
}

Bullet::Bullet(sf::Vector2f direction, sf::Vector2f startPosition)
{
	texture.loadFromFile("Resources/Bullet.png");
	sprite.setTexture(texture);

	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	sprite.setPosition(startPosition);

	this->direction = direction;
	speed = 1000.0f;

	timeAlive = 5;

	bullets.push_back(this);
}

void Bullet::AsteroidCollision()
{
	for (int i = 0; i < Asteroid::GetAsteroids().size(); i++)
	{
		for (int j = 0; j < bullets.size(); j++)
		{
			if (bullets[j]->sprite.getGlobalBounds().intersects(Asteroid::GetAsteroids()[i]->GetSprite().getGlobalBounds()))
			{
				Asteroid::DeleteAsteroid(i, false);
				DeleteBullet(j);
			}
		}
	}
}

void Bullet::MoveBullets()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->timeAlive -= General::GetDeltaTime();
		if (bullets[i]->timeAlive <= 0)
		{
			DeleteBullet(i);
		}
		else
		{
			General::window.draw(bullets[i]->sprite);
			bullets[i]->sprite.move(bullets[i]->direction * bullets[i]->speed * General::GetDeltaTime());
		}
	}
}
