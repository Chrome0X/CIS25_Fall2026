#include <SFML/Graphics.hpp>
#include <iostream>
#include "header.h"

int main() {

    bool gameOver = false;
    int enemiesDefeated = 0;
    const int ENEMIES_TO_WIN = 25;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Project SS");

    Player player;
    std::vector<Enemy> enemies;
    std::vector<Projectile> projectiles;

    sf::Clock clock;

    sf::RectangleShape debugBackground;
    debugBackground.setSize({800.f, 600.f});
    debugBackground.setFillColor(sf::Color(50, 50, 150));
    while (window.isOpen()) {

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();

                // Fire projectile
                // Up
                if (key->scancode == sf::Keyboard::Scancode::Space) {
                    projectiles.emplace_back(player.shape.getPosition(), sf::Vector2f(0.f, -1.f));
                }
                // Left
                if (key->scancode == sf::Keyboard::Scancode::A) {
                    projectiles.emplace_back(player.shape.getPosition(), sf::Vector2f(-1.f, 0.f));
                }
                // Right
                if (key->scancode == sf::Keyboard::Scancode::D) {
                    projectiles.emplace_back(player.shape.getPosition(), sf::Vector2f(1.f, 0.f));
                }
            }
        }

        float dt = clock.restart().asSeconds();        

        // random enemy spawn
        if (rand() % 100 < 0.4)
            spawnEnemy(enemies);

        if (!gameOver) {
        // Do updates only if the game is running
        player.update(dt);
        updateEnemies(enemies, player.shape.getPosition(), dt);
        updateProjectiles(projectiles, dt);
        }

        // Collision: projectile → enemy
        for (int i=0; i < enemies.size(); i++) {
            for (int j=0; j < projectiles.size(); j++) {
                if (intersects(projectiles[j].shape.getGlobalBounds(),
                    enemies[i].shape.getGlobalBounds())) {
                    enemies.erase(enemies.begin() + i);
                    projectiles.erase(projectiles.begin() + j);
                    enemiesDefeated++;

                    if (enemiesDefeated >= ENEMIES_TO_WIN) {
                        gameOver = true;
                    }
                    goto skip;
                }
            }
        }
        skip:;

        // Collision: enemy → player
        for (int i=0; i < enemies.size(); i++) {
            if (intersects(enemies[i].shape.getGlobalBounds(),
                   player.shape.getGlobalBounds())) {
                    player.health -= 10;
                    enemies.erase(enemies.begin() + i);
                    if (player.health <= 0) {
                        gameOver = true;
                    }
                }
            }

        window.clear();
        window.draw(debugBackground);
        window.draw(player.shape);
        for (auto &e : enemies) window.draw(e.shape);
        for (auto &p : projectiles) window.draw(p.shape);

        
        window.display();
    }
}