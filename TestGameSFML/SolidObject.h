#pragma once

#include "Math.h"
#include "GameObject.h"

class SolidObject : public GameObject {
public:
	SolidObject();
	int checkCollision(GameObject* go1);

protected:

};
