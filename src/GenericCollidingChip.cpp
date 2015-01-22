#ifndef _GENERIC_COLLIDING_CPP
#define _GENERIC_COLLIDING_CPP

#include "GenericCollidingChip.h"

GenericCollidingChip::GenericCollidingChip() {
	this->radius = 0;
}

GenericCollidingChip::~GenericCollidingChip() {
	
}

void GenericCollidingChip::setRadius(float radius) {
	this->radius = radius;
}

float GenericCollidingChip::getRadius() {
	return this->radius;
}

bool GenericCollidingChip::isColliding(GenericCollidingChip chip) { 
	float xx = this->positionX - chip.getPositionX();
	float yy = this->positionY - chip.getPositionY();
	float d = (xx*xx) + (yy*yy);
	float dd = this->radius + chip.getRadius();
	float ddd = dd * dd;
	return d < ddd;
}

#endif