#ifndef _GENERIC_COLLIDING_CPP
#define _GENERIC_COLLIDING_CPP

#include "GenericCollidingChip.h"
#include <cmath>

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
	float distance = sqrt((xx*xx) + (yy*yy));
	return distance < this->radius + chip.getRadius();
}

#endif