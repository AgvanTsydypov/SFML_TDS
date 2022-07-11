#pragma once
#include "SolidObject.h"

class Character : public SolidObject
{
public:
	Character();

	/// <summary>
	/// Applies damage to the character. If it's health drops below zero it is
	/// marked to be destroyed.
	/// </summary>
	void takeDamage(float damage);

protected:
	float maxHealth = 1.f;
	float health;

	float defaultSpeed;
	
	// \brief Defines rotation speed
	float mass;

	sf::Vector2f movementVector;
};
