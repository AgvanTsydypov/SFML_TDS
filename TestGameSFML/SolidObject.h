#pragma once

#include "Math.h"
#include "GameObject.h"

class SolidObject : public GameObject {
public:
	SolidObject();
	void tick(TickData& tickData);
	int checkCollision(GameObject* go1);

private:
	int health = 100;
};

