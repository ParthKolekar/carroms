#ifndef _COIN_CPP
#define _COIN_CPP

#include "Coin.h"
#include <GL/glut.h>
#include <cmath>

extern int STATE;

// 0 - black;
// 1 - white;
// 2 - red;

Coin::Coin() {
	this->type = 0;
	this->radius = 0.15;
	this->mass = 0.5;
	this->pocketed = false;
}

Coin::~Coin() {

}

Coin::Coin(int type, float positionX, float positionY) {
	this->type = type;
	this->positionX = positionX;
	this->positionY = positionY;
	this->radius = 0.15;
	this->pocketed = false;
	this->mass = 0.5;
}

void Coin::setType(int type) {
	this->type = type;
}

int Coin::getType() {
	return this->type;
}

bool Coin::isPocketed() {
	return this->pocketed;
}

void Coin::pocketSelf() {
	this->stopSelf();
	this->setPosition(8 + this->type, -4 + (STATE * 0.5));
	this->pocketed = true;
	STATE = STATE + 1;
}

void Coin::drawSelf() {
	glPushMatrix();
	glTranslatef(this->positionX , this->positionY , 0);
	switch (this->type) {
		case 0:
			glColor4f(0.83,0.92,0.2,0.1);
			break;
		case 1:
			glColor4f(0.2,0.92,0.85,0.1);
			break;
		case 2:
			glColor4f(1,0.1,0.1,0.1);
			break;
		default:
			glColor4f(1,1,1,0.1);
			break;
	}	
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0 ; i < 360 ; i++) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();
	switch (this->type) {
		case 0:
			glColor4f(0.83,0.92,0.2,0.1);
			break;
		case 1:
			glColor4f(0.2,0.92,0.85,0.1);
			break;
		case 2:
			glColor4f(1,0.1,0.1,0.1);
			break;
		default:
			glColor4f(1,1,1,0.1);
			break;
	}
	glBegin(GL_LINE_LOOP);	
	for (float i = 0 ; i < 360 ; i += 0.25) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();
	switch (this->type) {
		case 0:
			glColor4f(0.83,0.92,0.2,0.1);
			break;
		case 1:
			glColor4f(0.2,0.92,0.85,0.1);
			break;
		case 2:
			glColor4f(1,0.1,0.1,0.1);
			break;
		default:
			glColor4f(1,1,1,0.1);
			break;
	}
	glBegin(GL_LINE_LOOP);	
	for (float i = 0 ; i < 360 ; i += 0.25) {
		glVertex2f((this->radius + 0.01) * cos(M_PI * i / 180) , (this->radius + 0.01) * sin(M_PI * i / 180));
	}
	glEnd();
	glPopMatrix();
}

int Coin::getScore() {
	switch (this->type) {
		case 0:
			return 10;
		case 1:
			return -5;
		case 2:
			return 50;
		default:
			return 0;
	}
}

#endif