#include "Asteroid.h"

void Asteroid::DeleteAsteroid(int index, bool deleteCompletely)
{
	if (!asteroids[index]->isSmallAsteroid && !deleteCompletely)
	{
		sf::Vector2f newDirection;

		float randomAngle = rand() % 360 * 3.14f / 180.0f;

		newDirection.x = cos(randomAngle);
		newDirection.y = sin(randomAngle);

		Asteroid* firstSmallAsteroid = new Asteroid(asteroids[index]->sprite.getPosition(), newDirection, true);
		firstSmallAsteroid->sprite.setScale(firstSmallAsteroid->sprite.getScale() / 2.0f);

		newDirection.x *= -1;
		newDirection.y *= -1;

		Asteroid* secondSmallAsteroid = new Asteroid(asteroids[index]->sprite.getPosition(), newDirection, true);
		secondSmallAsteroid->sprite.setScale(secondSmallAsteroid->sprite.getScale() / 2.0f);
	}

	delete asteroids[index];
	asteroids[index] = nullptr;
	asteroids.erase(asteroids.begin() + index);
}

void Asteroid::DeleteAllAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		DeleteAsteroid(i, true);
	}
}

Asteroid::Asteroid(sf::Vector2f startPosition, sf::Vector2f direction, bool isSmallAsteroid)
{
	texture.loadFromFile("Resources/Large Asteroid.png");
	sprite.setTexture(texture);

	sprite.setPosition(startPosition);
	this->direction = direction;

	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	this->isSmallAsteroid = isSmallAsteroid;

	speed = 100.0f;

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

void Asteroid::SpawnAsteroids(int count)
{
	srand(time(0));

	for (; count > 0; count--)
	{
		sf::Vector2f randomPosition;
		sf::Vector2f randomDirection;

		do
		{
			randomPosition.x = rand() % General::windowWidth;
			randomPosition.y = rand() % General::windowHeight;
		} while ((randomPosition.x >= General::windowWidth / 4.0f
			&& randomPosition.x <= General::windowWidth - General::windowWidth / 4.0f)
			|| (randomPosition.y >= General::windowHeight / 4.0f
			&& randomPosition.y <= General::windowHeight - General::windowHeight / 4.0f));

		float randomAngle = rand() % 360 * 3.14f / 180.0f;
		randomDirection.x = cos(randomAngle);
		randomDirection.y = sin(randomAngle);

		Asteroid* asteroid = new Asteroid(randomPosition, randomDirection, false);
	}
}

void Asteroid::MoveAsteroids()
{
	for (int i = 0; i < asteroids.size(); i++)
	{
		asteroids[i]->sprite.move(asteroids[i]->direction * asteroids[i]->speed * General::GetDeltaTime());
		General::window.draw(asteroids[i]->sprite);

		General::BorderTeleport(asteroids[i]->sprite);
	}
}
