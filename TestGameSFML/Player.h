#pragma once

#include "Math.h"
#include "GameObject.h"

class Player : public GameObject {
public:
	Player();

	void tick(TickData & tickData);

private:
	float movementSpeed = 500.f;

	sf::Clock shotTimer;
	float shotDelay = 0.1f;
};

