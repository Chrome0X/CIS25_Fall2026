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

Player::Player() : texture(), sprite(texture) {
    texture.loadFromFile("assets/player.png");
    sprite.setOrigin({
        static_cast<float>(texture.getSize().x) / 2.f,
        static_cast<float>(texture.getSize().y) / 2.f
    });
    sprite.setPosition({400.f, 300.f});
}

void Player::update(float dt) {
    // player does not move in this game
}


Enemy::Enemy(float speed) : speed(speed), texture(), sprite(texture) {
    texture.loadFromFile("assets/enemy.png");
    sprite.setOrigin({
        static_cast<float>(texture.getSize().x) / 2.f,
        static_cast<float>(texture.getSize().y) / 2.f
    });

    float y = static_cast<float>(rand() % 600);
    if (rand() % 2 == 0)
        sprite.setPosition({0.f, y});
    else
        sprite.setPosition({800.f, y});
}

Projectile::Projectile(sf::Vector2f startPos) {
    shape.setRadius(5.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setPosition(startPos);
    shape.setOrigin({5.f, 5.f});
}

void spawnEnemy(std::vector<Enemy>& enemies) {
    enemies.emplace_back(100.f);
}

void updateEnemies(std::vector<Enemy>& enemies, sf::Vector2f playerPos, float dt) {
    for (auto &e : enemies) {
        sf::Vector2f dir = playerPos - e.sprite.getPosition();

        float len = std::sqrt(dir.x*dir.x + dir.y*dir.y);
        if (len != 0) dir /= len;

        e.sprite.move(dir * e.speed * dt);
    }
}

void updateProjectiles(std::vector<Projectile>& projectiles, float dt) {
    for (auto &p : projectiles)
        p.shape.move({0.f, -p.speed * dt});
}