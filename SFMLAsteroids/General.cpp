#include "General.h"

void General::UpdateClock()
{
	deltaTime = clock.getElapsedTime().asSeconds();
	clock.restart();
}

float General::GetDeltaTime()
{
	return deltaTime;
}

float General::GetVectorLenght(sf::Vector2f vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}
