#pragma once

#include "TDS.h"
#include "App.h"
#include "GameObject.h"

class Bullet : public GameObject {
public:
	Bullet();

	void tick(TickData & tickData);

	void setMovementDirection(sf::Vector2f);
	void setMovementDirection();

private:
	const float defaultSpeed = 500.f;
	
	sf::Vector2f movementVector;
	
	// \brief Time before self-destruction
	float bulletLifeTimer = 100.f;
};

