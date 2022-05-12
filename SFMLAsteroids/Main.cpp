#include <SFML/Graphics.hpp>

#include "Ship.h"
#include "General.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Loss.h"

#include <iostream>

sf::Clock General::clock;
float General::deltaTime;

std::vector<Bullet*> Bullet::bullets;

sf::RenderWindow General::window;
int General::windowWidth;
int General::windowHeight;

std::vector<Asteroid*> Asteroid::asteroids;

sf::Font Loss::font;
sf::Text Loss::text;

int Loss::fontSize;
sf::Color Loss::color;
bool Loss::isLoss = false;

int main()
{
    General::windowWidth = sf::VideoMode::getDesktopMode().width;
    General::windowHeight = sf::VideoMode::getDesktopMode().height;
    General::window.create(sf::VideoMode::getDesktopMode(), "Asteroids!", sf::Style::Fullscreen);
    General::window.setVerticalSyncEnabled(true);

    Ship* ship = new Ship(General::windowWidth / 2, General::windowHeight / 2);

    Asteroid::SpawnAsteroids(5);

    Loss::InitializeLoss();

    while (General::window.isOpen())
    {
        sf::Event event;
        while (General::window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                General::window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space && !Loss::isLoss)
                {
                    ship->Shoot();
                }
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            General::window.close();
        }

        General::window.clear();

        if (!Loss::isLoss)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                ship->Rotate(360);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                ship->Rotate(-360);
            }

            ship->Move();
            General::BorderTeleport(ship->GetSprite());

            Bullet::MoveBullets();
            Asteroid::MoveAsteroids();
            Bullet::AsteroidCollision();

            ship->LossCheck();
        }
        else
        {
            Loss::Restart(*ship);
        }

        General::window.display();

        General::UpdateClock();
    }

    return 0;
}