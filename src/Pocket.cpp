#ifndef _POCKET_CPP
#define _POCKET_CPP

#include "Pocket.h"
#include <GL/glut.h>
#include <cmath>

#include <iostream>

// 0 - un-initialised
// 1 - 1st quad
// 2 - 2nd quad
// 3 - 3rd quad
// 4 - 4th quad

Pocket::Pocket() {
	this->orientation = 0;
	this->radius = 0.5;
}

Pocket::~Pocket() {

}

Pocket::Pocket(int orientation, float positionX, float positionY) {
	this->radius = 0.5;
	this->orientation = orientation;
	this->positionX = positionX;
	this->positionY = positionY;
}

void Pocket::setOrientation(int orientation) {
	this->orientation = orientation;
}

int Pocket::getOrientation() {
	return this->orientation;
}

void Pocket::drawSelf() {
	glPushMatrix();
	glTranslatef(this->positionX , this->positionY , 0);

	glColor4f(0,0,0,1);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0 ; i < 360 ; i++) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();

	int initial;
	int final;

	switch (this->orientation) {
		case 1:
			initial = -90;
			final = 180;
			break;
		case 2:
			initial = -180;
			final = 90;
			break;
		case 3:
			initial = -270;
			final = 0;
			break;
		case 4:
			initial = 0;
			final = 270;
			break;
		default:
			initial = 0;
			final = 0;
			break;
	}

	glColor4f(1,1,1,1);
	glBegin(GL_LINE_STRIP);	
	for (float i = initial ; i < final ; i += 0.125) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();

	glColor4f(0.3,0.3,0.9,0.7);
	glBegin(GL_LINE_STRIP);	
	for (float i = initial ; i < final ; i += 0.125) {
		glVertex2f((this->radius + 0.01) * cos(M_PI * i / 180) , (this->radius + 0.01) * sin(M_PI * i / 180));
	}
	glEnd();

	glColor4f(0.5,0.5,0.9,0.7);
	glBegin(GL_LINE_STRIP);	
	for (float i = initial ; i < final ; i += 0.125) {
		glVertex2f((this->radius - 0.01) * cos(M_PI * i / 180) , (this->radius - 0.01) * sin(M_PI * i / 180));
	}
	glEnd();

	glPopMatrix();
}

bool Pocket::isFullyEncompassing(GenericCollidingChip chip) {
	// Assumption made that Pocket is > chip. (As it should be.). Do you even expect a fair game otherwise? :P
	float xx = chip.getPositionX() - this->positionX;
	float yy = chip.getPositionY() - this->positionY;
	float len = xx * xx + yy * yy;
	float xxx = this->radius - chip.getRadius();
	float len2 = xxx * xxx;
	return len <= len2;
}

#endif