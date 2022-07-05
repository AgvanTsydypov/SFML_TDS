#include "Bullet.h"

Bullet::Bullet(float time, sf::Vector2f bullet_speed, sf::Vector2f pos) {
	shape.setPosition(pos);
	shape.setRadius(7.f);
	shape.setPointCount(4);
	shape.setFillColor(sf::Color::Magenta);

	timer = time;

	speed = bullet_speed;

	to_destroy = false;
}

void Bullet::bullet_new_pos(sf::Vector2f pos) {
	shape.setPosition(pos);
}

void Bullet::tick(float dt) {
	shape.move(speed * dt);
	
	timer -= dt;

	if (timer <= 0) {
		to_destroy = true;
	}
}