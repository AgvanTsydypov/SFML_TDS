#pragma once

#include "GameObject.h"

class Player : public GameObject {
public:
	Player();

	void tick(TickData & tickData);

private:
	float movementSpeed = 500.f;
};

