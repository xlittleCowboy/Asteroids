#include <SFML/Graphics.hpp>

#include "Ship.h"
#include "General.h"
#include "Bullet.h"
#include "Asteroid.h"

#include <iostream>

sf::Clock General::clock;
float General::deltaTime;

std::vector<sf::Sprite*> General::sprites;

std::vector<Bullet*> Bullet::bullets;

sf::RenderWindow General::window;
int General::windowWidth;
int General::windowHeight;

std::vector<Asteroid*> Asteroid::asteroids;

int main()
{
    General::windowWidth = sf::VideoMode::getDesktopMode().width;
    General::windowHeight = sf::VideoMode::getDesktopMode().height;
    General::window.create(sf::VideoMode::getDesktopMode(), "Asteroids!", sf::Style::Fullscreen);
    General::window.setVerticalSyncEnabled(true);

    Ship ship(General::windowWidth / 2, General::windowHeight / 2);
    Asteroid asteroid(sf::Vector2f(500.0f, 500.0f), sf::Vector2f(1.23f, -3.41f));

    while (General::window.isOpen())
    {
        sf::Event event;
        while (General::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                General::window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    ship.Shoot();
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            General::window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            ship.Rotate(360);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            ship.Rotate(-360);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            //ship.Shoot();
        }

        General::window.clear();

        ship.Move();
        ship.BorderTeleport(General::windowWidth, General::windowHeight);

        Bullet::MoveBullets();
        Asteroid::MoveAsteroids();

        General::window.display();

        General::UpdateClock();
    }

    return 0;
}