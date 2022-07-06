#pragma once

#include "TDS.h"
#include "App.h"
#include "GameObject.h"

class Bullet : public GameObject {
public:
	Bullet();

	void bulletSetSpeed(sf::Vector2f);
	void bulletSetSpeed();

	void tick();

private:
	// \brief Time before self-destruction
	float timer;
	sf::Vector2f speed;
	const float realSpeed = 300.f;
};

