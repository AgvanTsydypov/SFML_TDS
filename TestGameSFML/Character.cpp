#include "Character.h"

void Character::takeDamage(float damage) {
	health -= damage;

	if (health <= 0) {
		toDestroy = true;
	}
}
