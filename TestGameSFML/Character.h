#pragma once
#include "SolidObject.h"

class Character : public SolidObject
{
public:
	void takeDamage(float damage);

protected:
	float maxHealth = 1.f;
	float health;
};
