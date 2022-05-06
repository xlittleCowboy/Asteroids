#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "General.h"

class Asteroid
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f direction;
	float speed;

	static std::vector<Asteroid*> asteroids;

public:
	Asteroid(sf::Vector2f startPosition, sf::Vector2f direction);

	static void MoveAsteroids();
};

