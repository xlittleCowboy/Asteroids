#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "General.h"

class Bullet
{
private:
	static std::vector<Bullet*> bullets;

	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f direction;
	float speed;

	float timeAlive;

public:
	Bullet(sf::Vector2f direction, sf::Vector2f startPosition);

	static void MoveBullets();
};

