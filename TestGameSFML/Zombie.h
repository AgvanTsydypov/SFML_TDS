#pragma once
#include "Enemy.h"
#include "SteeringBehaviors.h"

class Zombie : public Enemy
{
public:
	Zombie();

	void tick(TickData & tickData);

private:
	float maxHealth = 100;
	float defaultSpeed = 70.f;
	float mass = 4.5f;
};

