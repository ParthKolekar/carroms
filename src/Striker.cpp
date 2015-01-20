#ifndef _STRIKER_CPP
#define _STRIKER_CPP 

#include "Striker.h"
#include <GL/glut.h>
#include <cmath>


Striker::Striker() {
	this->deltaX_next = 0;
	this->deltaY_next = 0;
	this->radius = 0.22;
	this->positionX = 0;
	this->positionY = -10/2.75;
}

Striker::~Striker() {

}

float Striker::getDeltaXNext() {
	return this->deltaX_next;
}

float Striker::getDeltaYNext() {
	return this->deltaY_next;
}

void Striker::setDeltaNext(float deltaX, float deltaY) {
	this->deltaX_next = deltaX;
	this->deltaY_next = deltaY;
}

void Striker::fire() {
	this->deltaX = this->deltaX_next;
	this->deltaX_next = 0;
	this->deltaY = this->deltaY_next;
	this->deltaY_next = 0;
}

void Striker::drawSelf() {
	glPushMatrix();
	glTranslatef(this->positionX , this->positionY , 0);
	glColor4f(0.7,0.4,0.8,1);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0 ; i < 360 ; i++) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();
	glColor4f(0.7,0.4,0.8,0.3);
	glBegin(GL_LINE_LOOP);	
	for (float i = 0 ; i < 360 ; i += 0.25) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();
	glColor4f(0.7,0.4,0.8,0.3);
	glBegin(GL_LINE_LOOP);	
	for (float i = 0 ; i < 360 ; i += 0.25) {
		glVertex2f((this->radius + 0.01) * cos(M_PI * i / 180) , (this->radius + 0.01) * sin(M_PI * i / 180));
	}
	glEnd();
	glPopMatrix();
}

#endif