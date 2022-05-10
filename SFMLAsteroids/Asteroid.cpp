#include "Asteroid.h"

void Asteroid::DeleteAsteroid(int index)
{
	delete asteroids[index];
	asteroids[index] = nullptr;
	asteroids.erase(asteroids.begin() + index);
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f direction)
{
	texture.loadFromFile("Resources/Large Asteroid.png");
	sprite.setTexture(texture);

	sprite.setPosition(startPosition);
	this->direction = direction;

	speed = 10.0f;

	asteroids.push_back(this);
}

std::vector<Asteroid*>& Asteroid::GetAsteroids()
{
	return asteroids;
}

sf::Sprite& Asteroid::GetSprite()
{
	return sprite;
}

void Asteroid::MoveAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i]->sprite.move(asteroids[i]->direction * asteroids[i]->speed * General::GetDeltaTime());
		General::window.draw(asteroids[i]->sprite);
	}
}
