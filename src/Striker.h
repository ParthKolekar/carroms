#ifndef _STRIKER_H
#define _STRIKER_H

#include "GenericCollidingChip.h"

class Striker : public GenericCollidingChip
{
	float power;
	float angle;
	bool fired;
public:
	Striker();
	~Striker();

	void drawSelf();
	void drawPowerArrow();

	void setPower(float);
	void setAngle(int);

	void updatePower(float);
	void updateAngle(int);
	
	void fire();
	void reset();

	bool isFired();
	void updatePositionX(float);
	void setPositionX(float);
};

#endif