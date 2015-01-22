#ifndef _STRIKER_CPP
#define _STRIKER_CPP 

#include "Striker.h"
#include <GL/glut.h>
#include <cmath>

Striker::Striker() {
	this->radius = 0.22;
	this->positionX = 0;
	this->positionY = -10/2.75;
	this->mass = 1;
	this->angle = 90;
	this->power = 0.3;
	this->fired = false;
}

Striker::~Striker() {

}

void Striker::reset() {
	this->deltaX = 0;
	this->deltaY = 0;
	this->positionX = 0;
	this->positionY = -10/2.75;
	this->angle = 90;
	this->power = 0.3;
	this->fired = false;

}

void Striker::fire() {
	if (!this->fired) {
		this->deltaX = this->power * cos(M_PI * this->angle / 180);
		this->deltaY = this->power * sin(M_PI * this->angle / 180);
		this->power = 0;
		this->angle = 90;
		this->fired = true;
	}
}

bool Striker::isFired() {
	return this->fired;
}

void Striker::drawSelf() {
	glPushMatrix();
	glTranslatef(this->positionX , this->positionY , 0);
	glColor4f(0.7,0.4,0.8,0.25);
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
	this->drawPowerArrow();
	glPopMatrix();
}

void Striker::drawPowerArrow() {
	glColor4f(1,1,1,0.25);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(this->power*cos(M_PI * this->angle / 180) * 10 , this->power*sin(M_PI * this->angle / 180) * 10);
	glEnd();
	glColor4f(0.7,0.2,0.2,0.7);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(0.0001 + this->power*cos(M_PI * this->angle / 180) * 10 , 0.0001 + this->power*sin(M_PI * this->angle / 180) * 10);
	glEnd();
	glColor4f(0.7,0.2,0.2,0.7);
	glBegin(GL_LINES);
	glVertex2f(0,0);
	glVertex2f(-0.0001 + this->power*cos(M_PI * this->angle / 180) * 10 , -0.0001 + this->power*sin(M_PI * this->angle / 180) * 10);
	glEnd();
}

void Striker::updateAngle(int angle) {
	if (this->angle + angle <= 175 and this->angle + angle >= 5) {
		this->angle += angle;
	}
}

void Striker::updatePower(float power) {
	if (this->power + power <= 0.25 and this->power + power >= 0.01) {
		this->power += power;
	}
}

void Striker::setAngle(int angle) {
	if (angle <= 175 and angle >= 5) {
		this->angle = angle;
	}
}

void Striker::setPower(float power) {
	if (power < 0.25 and this->power >= 0.01) {
		this->power = power;
	}
}

void Striker::updatePositionX(float positionX) {
	if (this->positionX + positionX <= 10/2.75 and this->positionX + positionX >= -10/2.75 and !this->isFired()) {
		this->positionX += positionX;
	}
}

void Striker::setPositionX(float positionX) {
	if (positionX <= 10/2.75 and positionX >= -10/2.75 and !this->isFired()) {
		this->positionX = positionX;
	}
}

#endif