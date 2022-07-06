#include "Bullet.h"

Bullet::Bullet() {
	position = sf::Vector2f(0, 0);

	sprite = nullptr;
	sf::CircleShape* newShape = new sf::CircleShape(10.f, 5);
	newShape->setFillColor(sf::Color(120, 120, 120, 255));
	setShape(newShape);
	
	bulletLifeTimer = 10.f;

	bulletSetSpeed();
}

void Bullet::tick(TickData & tickData) {
	move(speed * tickData.deltaTime);
	
	bulletLifeTimer -= tickData.deltaTime;

	if (bulletLifeTimer <= 0) {
		toDestroy = true;
	}
}

void Bullet::bulletSetSpeed(sf::Vector2f bulletDirection) {
	speed = bulletDirection * realSpeed;
}

void Bullet::bulletSetSpeed() {
	speed = sf::Vector2f(realSpeed, 0.f);
}
