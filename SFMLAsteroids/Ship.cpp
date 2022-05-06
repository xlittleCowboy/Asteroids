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
	General::sprites.push_back(&sprite);

	sprite.setPosition(startX, startY);

	int x = sprite.getLocalBounds().width / 2;
	int y = sprite.getLocalBounds().height / 2;
	sprite.setOrigin(sf::Vector2f(x, y));

	velocity.x = 0;
	velocity.y = 0;
	speed = 10.0f;
	maxSpeed = 1000.0f;

	//std::cout << General::sprites.size() << std::endl;
	//Bullet* bullet = new Bullet(GetForwardVector(), sprite.getPosition() + GetForwardVector());
	//std::cout << General::sprites.size() << std::endl;
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

void Ship::BorderTeleport(int width, int height)
{
	if (sprite.getPosition().x + sprite.getLocalBounds().width / 2 <= 0)
		sprite.setPosition(width, sprite.getPosition().y);
	if (sprite.getPosition().x - sprite.getLocalBounds().width / 2 >= width)
		sprite.setPosition(0, sprite.getPosition().y);

	if (sprite.getPosition().y - sprite.getLocalBounds().height / 2 >= height)
		sprite.setPosition(sprite.getPosition().x, 0);
	if (sprite.getPosition().y + sprite.getLocalBounds().height / 2 <= 0)
		sprite.setPosition(sprite.getPosition().x, height);
}
