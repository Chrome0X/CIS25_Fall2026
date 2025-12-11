#include "header.h"
#include <cmath>
#include <cstdlib>

bool intersects(const sf::FloatRect& a, const sf::FloatRect& b)
{
    return (a.position.x < b.position.x + b.size.x &&
            a.position.x + a.size.x > b.position.x &&
            a.position.y < b.position.y + b.size.y &&
            a.position.y + a.size.y > b.position.y);
}

// ------------------ Player ------------------

Player::Player() {
    shape.setRadius(25.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin({25.f, 25.f});
    shape.setPosition({400.f, 300.f});
}

void Player::update(float dt) {
    // Player is stationary
}


Enemy::Enemy(float speed) : speed(speed) {
    shape.setSize({40.f, 40.f});
    shape.setFillColor(sf::Color::Red);
    shape.setOrigin({20.f, 20.f});

    float y = 250.f + static_cast<float>(rand() % 100);

    if (rand() % 2 == 0)
        shape.setPosition({0.f, y});
    else
        shape.setPosition({800.f, y});
}

Projectile::Projectile(sf::Vector2f startPos, sf::Vector2f dir)
{
    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin({5.f, 5.f});
    shape.setPosition(startPos);
    direction = dir;
}

void spawnEnemy(std::vector<Enemy>& enemies) {
    enemies.emplace_back(100.f);
}

void updateEnemies(std::vector<Enemy>& enemies, sf::Vector2f playerPos, float dt) {
    for (auto &e : enemies) {
        sf::Vector2f dir = playerPos - e.shape.getPosition();

        float len = std::sqrt(dir.x*dir.x + dir.y*dir.y);
        if (len != 0) dir /= len;

        e.shape.move(dir * e.speed * dt);
    }
}

void updateProjectiles(std::vector<Projectile>& projectiles, float dt) {
    for (auto &p : projectiles)
        p.shape.move(p.direction * p.speed * dt);
}