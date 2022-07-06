#pragma once

#include "TDS.h"
#include "App.h"
#include "GameObject.h"

class Bullet : public GameObject {
public:
	Bullet();

	void tick();

private:
	// \brief Time before self-destruction
	float timer;
	sf::Vector2f speed;
};

