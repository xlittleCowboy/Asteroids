#pragma once

#include <SFML/Graphics.hpp>

#include "General.h"
#include "Bullet.h"
#include "Loss.h"

class Ship
{
private:
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Vector2f velocity;
	float speed, maxSpeed;

	sf::Vector2f GetForwardVector();

public:
	Ship(int startX, int startY);

	void Move();
	void Rotate(float angle);
	void Shoot();

	void Reset(int startX, int startY);

	void LossCheck();

	sf::Sprite& GetSprite();
};

