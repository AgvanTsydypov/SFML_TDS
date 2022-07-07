#include "Bullet.h"

Bullet::Bullet() {
	position = sf::Vector2f(0, 0);

	sprite = nullptr;
	sf::CircleShape* shape = new sf::CircleShape(10.f, 3);
	shape->setFillColor(sf::Color(120, 120, 120, 255));
	setShape(shape);
	
	bulletLifeTimer = 7.f;

	setMovementDirection();
}

void Bullet::tick(TickData & tickData) {
	move(movementVector * tickData.deltaTime);
	
	bulletLifeTimer -= tickData.deltaTime;

	if (bulletLifeTimer <= 0) {
		toDestroy = true;
	}
}

void Bullet::setMovementDirection(sf::Vector2f bulletDirection) {
	movementVector = bulletDirection * defaultSpeed;
	setRotation(vectorAngle(movementVector) + 60);
}

void Bullet::setMovementDirection() {
	movementVector = sf::Vector2f(defaultSpeed, 0.f);
}
