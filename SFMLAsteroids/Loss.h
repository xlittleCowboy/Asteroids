#pragma once

#include <SFML/Graphics.hpp>

#include "General.h"
#include "Asteroid.h"
#include "Ship.h"

class Ship;

class Loss
{
private:
	static sf::Font font;
	static sf::Text text;

	static int fontSize;
	static sf::Color color;

public:
	static void InitializeLoss();

	static void Restart(Ship& ship);

	static bool isLoss;
};

