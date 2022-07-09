#include "Projectile.h"

void Projectile::tick(TickData& tickData) {
	move(movementVector * tickData.deltaTime);

	projectileLifeTime -= tickData.deltaTime;

	if (projectileLifeTime <= 0) {
		toDestroy = true;
	}
}

void Projectile::setMovementDirection(sf::Vector2f bulletDirection) {
	movementVector = bulletDirection * defaultSpeed;
	setRotation(vectorAngle(movementVector));
}

void Projectile::setMovementDirection() {
	movementVector = sf::Vector2f(defaultSpeed, 0.f);
}
