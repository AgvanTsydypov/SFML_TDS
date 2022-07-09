#pragma once

#include "Math.h"
#include "Character.h"

class Player : public Character {
public:
	Player();

	void tick(TickData & tickData);

private:
	float movementSpeed = 500.f;

	sf::Clock shotTimer;
	float shotDelay = 0.1f;
};

