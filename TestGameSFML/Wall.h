#pragma once
#include "SolidObject.h"

class Wall : public SolidObject
{
public:
	Wall();

	void tick(TickData & tickData);
};
