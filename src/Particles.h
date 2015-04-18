#ifndef _PARTICLES_H
#define _PARTICLES_H 

#include "GenericObject.h"

class Particles : public GenericObject
{
	float radius;
	bool isAlive;
	int timeToLive;
public:
	Particles();
	~Particles();
	Particles(float ,float ,float, float);

	void drawSelf();
	void moveNext();
	float getRadius();
	void setRadius(float radius);
};

#endif