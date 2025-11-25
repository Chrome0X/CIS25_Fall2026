#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>
#include <string>
#include "header.h"

using namespace std;

struct Player {
    sf::CircleShape shape;
    float speed;

    Player(float radius = 25.f, float speed = 200.f) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Green);
        shape.setOrigin({radius, radius}); // Center origin
        this->speed = speed;
    }
};

struct Enemy {
    sf::CircleShape shape;
    float speed;

    Enemy(float radius = 20.f, float speed = 100.f) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin({radius, radius});
        this->speed = speed;
    }
};

int main() {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Project SS");

    sf::Style::Close;

    Player player;
    player.shape.setPosition({400, 600}); // Center of screen

    std::vector<Enemy> enemies;

    sf::Clock clock;

    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
            
        }

        // Spawn enemies randomly on sides (example: left/right)
        if (rand() % 100 < 2) { // ~2% chance per frame
            Enemy e;
            float y = rand() % 600;
            float side = rand() % 2;
            if (side == 0) e.shape.setPosition({0, y});
            else e.shape.setPosition({800, y});
            enemies.push_back(e);
        }
    }

    float dt = clock.restart().asSeconds();

    for (auto &e : enemies) {
            sf::Vector2f dir = player.shape.getPosition() - e.shape.getPosition();
            float length = sqrt(dir.x * dir.x + dir.y * dir.y);
            dir /= length; // Normalize
            e.shape.move(dir * e.speed * dt);
        }

        window.clear(sf::Color::Black);
        window.draw(player.shape);
        for (auto &e : enemies) window.draw(e.shape);
        window.display();

    }
