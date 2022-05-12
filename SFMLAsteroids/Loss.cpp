#include "Loss.h"

void Loss::InitializeLoss()
{
	font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	text.setFont(font);

	fontSize = 24;
	color = sf::Color::White;

	text.setString("PRESS R TO RESTART");
	text.setCharacterSize(fontSize);
	text.setFillColor(color);
	text.setStyle(sf::Text::Bold);
	text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
	text.setPosition(General::windowWidth / 2.0f, General::windowHeight / 2.0f);
}

void Loss::Restart(Ship& ship)
{
	General::window.draw(text);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		isLoss = false;

		Asteroid::DeleteAllAsteroids();
		Asteroid::SpawnAsteroids(5);

		ship.Reset(General::windowWidth / 2.0f, General::windowHeight / 2.0f);
	}
}
