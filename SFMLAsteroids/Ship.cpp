#include "Ship.h"
#include <iostream>

sf::Vector2f Ship::GetForwardVector()
{
	sf::Vector2f forwardVector;

	forwardVector.x = sin(sprite.getRotation() * 3.14 / 180);
	forwardVector.y = -cos(sprite.getRotation() * 3.14 / 180);

	return forwardVector;
}

Ship::Ship(int startX, int startY)
{
	texture.loadFromFile("Resources/Ship.png");
	sprite.setTexture(texture);

	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);

	Reset(startX, startY);
	maxSpeed = 1000.0f;
}

void Ship::Move()
{
	sf::Vector2f newVelocity;
	sf::Vector2f friction;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		newVelocity = GetForwardVector();
		newVelocity *= speed;
	}

	if (General::GetVectorLenght(velocity) != 0)
		friction = velocity / General::GetVectorLenght(velocity);
	velocity += newVelocity - friction;



	if (General::GetVectorLenght(velocity) >= maxSpeed)
	{
		velocity /= General::GetVectorLenght(velocity);
		velocity *= maxSpeed;
	}

	sprite.move(velocity * General::GetDeltaTime());
	General::window.draw(sprite);
}

void Ship::Rotate(float angle)
{
	sprite.rotate(angle * General::GetDeltaTime());
}

void Ship::Shoot() 
{
	Bullet* bullet = new Bullet(GetForwardVector(), sprite.getPosition() + GetForwardVector() * sprite.getLocalBounds().height / 2.0f);
}

void Ship::Reset(int startX, int startY)
{
	sprite.setPosition(startX, startY);
	sprite.setRotation(0);

	velocity.x = 0;
	velocity.y = 0;
	speed = 10.0f;
}

void Ship::LossCheck()
{
	for (int i = 0; i < Asteroid::GetAsteroids().size(); i++)
	{
		if (sprite.getGlobalBounds().intersects(Asteroid::GetAsteroids()[i]->GetSprite().getGlobalBounds()))
		{
			Loss::isLoss = true;
		}
	}
}

sf::Sprite& Ship::GetSprite()
{
	return sprite;
}
