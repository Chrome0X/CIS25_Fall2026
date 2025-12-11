#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;


bool intersects(const sf::FloatRect& a, const sf::FloatRect& b);


struct Player {
    sf::CircleShape shape;
    int health = 200;

    Player();
    void update(float dt);
};

struct Enemy {
    sf::RectangleShape shape;
    float speed;

    Enemy(float speed = 100.f);
};

struct Projectile {
    sf::CircleShape shape;
    float speed = 500.f;
    sf::Vector2f direction;

    Projectile(sf::Vector2f startPos, sf::Vector2f dir);
};

void spawnEnemy(std::vector<Enemy>& enemies);
void updateEnemies(std::vector<Enemy>& enemies, sf::Vector2f playerPos, float dt);
void updateProjectiles(std::vector<Projectile>& projectiles, float dt);