#ifndef _PARTICLES_CPP
#define _PARTICLES_CPP 

#include "Particles.h"
#include <GL/glut.h>
#include <cmath>

Particles::Particles() {
	this->radius = 0.02;
	this->mass = 0.1;
	this->isAlive = true;
	this->timeToLive = 10;
}

Particles::~Particles() {
	
}

Particles::Particles(float positionX, float positionY, float deltaX, float deltaY) {
	this->positionX = positionX;
	this->positionY = positionY;
	this->deltaX = deltaX;
	this->deltaY = deltaY;
	this->radius = 0.02;
	this->mass = 0.1;
	this->isAlive = true;
	this->timeToLive = 50;
}

void Particles::drawSelf() {
	if (this->isAlive) {
		glPushMatrix();
		glTranslatef(this->positionX , this->positionY , 0);

		glColor4f(0.7 - (this->getDeltaMagnitude() * 20), 0.7 - (this->getDeltaMagnitude() * 10), this->getDeltaMagnitude() * 10, 1);
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0 ; i < 360 ; i++) {
			glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
		}
		glEnd();
		glPopMatrix();
	}
}

float Particles::getRadius() {
	return this->radius;
}

void Particles::setRadius(float radius) {
	this->radius = radius;
}

void Particles::moveNext() {
	if (this->isAlive) {
		this->timeToLive = this->timeToLive - 1;
		if (this->timeToLive <= 0) {
			this->isAlive = false;
		}
		GenericObject::moveNext();
	}
}

#endif