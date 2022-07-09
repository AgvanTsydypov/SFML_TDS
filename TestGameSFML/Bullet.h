#pragma once

#include "TDS.h"
#include "App.h"
#include "Projectile.h"

class Bullet : public Projectile {
public:
	Bullet();

	void tick(TickData & tickData);

	void setMovementDirection();
	void setMovementDirection(sf::Vector2f bulletDirection);

protected:
	float defaultSpeed = 500.f;
	
	sf::Vector2f movementVector;
	
	// \brief Time before self-destruction
	float projectileLifeTime = 100.f;

	float damage = 10.f;
};
