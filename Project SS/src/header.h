#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;


bool intersects(const sf::FloatRect& a, const sf::FloatRect& b);

struct Player {
    sf::Texture texture;
    sf::Sprite sprite;
    int health = 100;

    Player();
    void update(float dt);
};

struct Enemy {
    sf::Texture texture;
    sf::Sprite sprite;
    float speed;
    Enemy(float speed = 100.f);
};

struct Projectile {
    sf::CircleShape shape;
    float speed = 500.f;

    Projectile(sf::Vector2f startPos);
};

void spawnEnemy(std::vector<Enemy>& enemies);
void updateEnemies(std::vector<Enemy>& enemies, sf::Vector2f playerPos, float dt);
void updateProjectiles(std::vector<Projectile>& projectiles, float dt);