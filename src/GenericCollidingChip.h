#ifndef _GENERIC_COLLIDING_CHIP_H
#define _GENERIC_COLLIDING_CHIP_H

#include "GenericObject.h"

class GenericCollidingChip : public GenericObject
{
protected:
	float radius;

public:
	GenericCollidingChip();
	~GenericCollidingChip();

	void setRadius(float);

	float getRadius();
	bool isColliding(GenericCollidingChip);
};

#endif