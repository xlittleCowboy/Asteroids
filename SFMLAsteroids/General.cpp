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

void General::BorderTeleport(sf::Sprite& sprite)
{
	float delta = 5.0f;

	if (sprite.getPosition().x + sprite.getLocalBounds().width / 2 <= 0 - delta)
		sprite.setPosition(windowWidth + sprite.getLocalBounds().width / 2, sprite.getPosition().y);
	if (sprite.getPosition().x - sprite.getLocalBounds().width / 2 >= windowWidth + delta)
		sprite.setPosition(-sprite.getLocalBounds().width / 2, sprite.getPosition().y);

	if (sprite.getPosition().y - sprite.getLocalBounds().height / 2 >= windowHeight + delta)
		sprite.setPosition(sprite.getPosition().x, -sprite.getLocalBounds().height / 2);
	if (sprite.getPosition().y + sprite.getLocalBounds().height / 2 <= 0 - delta)
		sprite.setPosition(sprite.getPosition().x, windowHeight + sprite.getLocalBounds().height / 2);
}
