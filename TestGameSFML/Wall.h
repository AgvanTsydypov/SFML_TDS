#pragma once
#include "SolidObject.h"

class Wall : public SolidObject
{
public:
	void tick(TickData & tickData);
};
