#pragma once
#include "SolidObject.h"

class Projectile : public SolidObject
{
public:
	void tick(TickData& tickData);

	void setMovementDirection(sf::Vector2f bulletDirection);
	void setMovementDirection();

protected:
	float defaultSpeed = 1.f;

	sf::Vector2f movementVector;

	// \brief Time before self-destruction
	float projectileLifeTime = 7.f;

	float damage = 0.f;
};
