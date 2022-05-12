#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

#include "General.h"

class Asteroid
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f direction;
	float speed;

	bool isSmallAsteroid;

	static std::vector<Asteroid*> asteroids;


public:
	Asteroid(sf::Vector2f startPosition, sf::Vector2f direction, bool isSmallAsteroid);

	static void DeleteAsteroid(int index, bool deleteCompletely);
	static void DeleteAllAsteroids();

	static std::vector<Asteroid*>& GetAsteroids();
	sf::Sprite& GetSprite();

	static void SpawnAsteroids(int count);

	static void MoveAsteroids();
};

