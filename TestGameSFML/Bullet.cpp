#include "Bullet.h"

Bullet::Bullet() {
	position = sf::Vector2f(0, 0);

	sprite = nullptr;
	shape = new sf::CircleShape(7.f, 5);
	shape->setFillColor(sf::Color::Magenta);
	
	timer = 2.f;

	speed = sf::Vector2f(100.f, 0.f);
}

void Bullet::tick() {
	move(speed * App::deltaTime);
	
	timer -= App::deltaTime;

	if (timer <= 0) {
		toDestroy = true;
	}
}