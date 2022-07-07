#pragma once

#include "GameObject.h"

#define PI 3.14159265 

class SolidObject : public GameObject {
public:
	SolidObject();
	void tick(TickData& tickData);
	int checkCollision(GameObject* go1);
	float cosF(sf::Vector2f a, sf::Vector2f b);

private:

};

