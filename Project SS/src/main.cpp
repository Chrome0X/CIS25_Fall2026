#include <SFML/Graphics.hpp>
#include <iostream>
#include "header.h"

int main() {

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Project SS");

    Player player;
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    sf::Clock clock;

    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();

                // Fire projectile
                if (key->scancode == sf::Keyboard::Scancode::Space) {
                    projectiles.emplace_back(player.sprite.getPosition());
                }
            }
        }

        float dt = clock.restart().asSeconds();

        // random enemy spawn
        if (rand() % 100 < 2)
            spawnEnemy(enemies);

        player.update(dt);
        updateEnemies(enemies, player.sprite.getPosition(), dt);
        updateProjectiles(projectiles, dt);

        // collision: projectile → enemy
        for (int i=0; i < enemies.size(); i++) {
            for (int j=0; j < projectiles.size(); j++) {
                if (intersects(projectiles[j].shape.getGlobalBounds(),
                    enemies[i].sprite.getGlobalBounds())) {
                    enemies.erase(enemies.begin() + i);
                    projectiles.erase(projectiles.begin() + j);
                    goto skip;
                }
            }
        }
        skip:;

        // collision: enemy → player
        for (int i=0; i < enemies.size(); i++) {
            if (intersects(enemies[i].sprite.getGlobalBounds(),
                   player.sprite.getGlobalBounds())) {
                    player.health -= 10;
                    enemies.erase(enemies.begin() + i);
                }
            }
        }

        window.clear(sf::Color::Black);

        window.draw(player.sprite);
        for (auto &e : enemies) window.draw(e.sprite);
        for (auto &p : projectiles) window.draw(p.shape);

        window.display();
    }