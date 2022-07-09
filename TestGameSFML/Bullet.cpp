#include "Bullet.h"
#include "Enemy.h"
#include "Wall.h"

Bullet::Bullet() {
	position = sf::Vector2f(0, 0);

	sprite = nullptr;
	sf::CircleShape* shape = new sf::CircleShape(10.f, 3);
	shape->setFillColor(sf::Color(120, 120, 120, 255));
	setShape(shape);

	setMovementDirection();
}

void Bullet::tick(TickData & tickData) {
	move(movementVector * tickData.deltaTime);
	
	projectileLifeTime -= tickData.deltaTime;

    for (size_t i = 0; i < tickData.gameObjects->size(); i++) {
        if (toDestroy)
            break;
        GameObject* obj = (*tickData.gameObjects)[i];

        // Enemy
		Enemy* enemy = dynamic_cast<Enemy*>(obj);
        if (enemy != nullptr) {
            if (checkCollision(enemy)) {
				enemy->takeDamage(damage);
				
				toDestroy = true;
            }
        }

		// Wall
		Wall* wall = dynamic_cast<Wall*>(obj);
		if (wall != nullptr) {
			if (checkCollision(wall)) {
				toDestroy = true;
			}
		}
    }

	if (projectileLifeTime <= 0) {
		toDestroy = true;
	}
}

void Bullet::setMovementDirection() {
	movementVector = sf::Vector2f(defaultSpeed, 0.f);
}

void Bullet::setMovementDirection(sf::Vector2f bulletDirection) {
	movementVector = bulletDirection * defaultSpeed;
	setRotation(vectorAngle(movementVector) + 60);
}
