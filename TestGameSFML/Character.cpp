#include "Character.h"

Character::Character() {
	health = maxHealth;

	defaultSpeed = 1.f;
	mass = 1.f;
}

void Character::takeDamage(float damage) {
	health -= damage;

	if (health <= 0) {
		toDestroy = true;
	}
}
