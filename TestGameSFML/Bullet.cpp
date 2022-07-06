#include "Bullet.h"

Bullet::Bullet() {
	position = sf::Vector2f(0, 0);

	sprite = nullptr;
	sf::CircleShape* newShape = new sf::CircleShape(10.f, 5);
	newShape->setFillColor(sf::Color(120, 120, 120, 255));
	setShape(newShape);
	
	timer = 2.f;

	bulletSetSpeed();
}

void Bullet::tick() {
	move(speed * App::deltaTime);
	
	timer -= App::deltaTime;

	if (timer <= 0) {
		toDestroy = true;
	}
}

void Bullet::bulletSetSpeed(sf::Vector2f bulletDirection) {
	speed = bulletDirection * realSpeed;
}

void Bullet::bulletSetSpeed() {
	speed = sf::Vector2f(realSpeed, 0.f);
}