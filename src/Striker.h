#ifndef _STRIKER_H
#define _STRIKER_H

#include "GenericCollidingChip.h"

class Striker : public GenericCollidingChip
{
	float deltaX_next;
	float deltaY_next;
public:
	Striker();
	~Striker();

	void drawSelf();

	float getDeltaXNext();
	float getDeltaYNext();

	void setDeltaNext(float, float);
	void fire();
};

#endif