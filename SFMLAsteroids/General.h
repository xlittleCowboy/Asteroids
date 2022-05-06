#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class General
{
private:
	static sf::Clock clock;
	static float deltaTime;

public:
	static void UpdateClock();
	static float GetDeltaTime();

	static float GetVectorLenght(sf::Vector2f vector);

	static std::vector<sf::Sprite*> sprites;

	static sf::RenderWindow window;
	static int windowWidth, windowHeight;
};

