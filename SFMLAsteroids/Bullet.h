#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "General.h"
#include "Asteroid.h"

class Bullet
{
private:

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f direction;
	float speed;

	float timeAlive;

	static std::vector<Bullet*> bullets;
	static void DeleteBullet(int index);

public:
	Bullet(sf::Vector2f direction, sf::Vector2f startPosition);

	static void AsteroidCollision();

	static void MoveBullets();
};

