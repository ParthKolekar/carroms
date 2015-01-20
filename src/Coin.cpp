#ifndef _COIN_CPP
#define _COIN_CPP

#include "Coin.h"
#include <GL/glut.h>
#include <cmath>

// 0 - black;
// 1 - white;
// 2 - red;

Coin::Coin() {
	this->type = 0;
	this->radius = 0.15;
}

Coin::~Coin() {

}

void Coin::drawSelf() {
	glPushMatrix();
	glTranslatef(this->positionX , this->positionY , 0);
	glColor4f(1,1,0.1,1);
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0 ; i < 360 ; i++) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();
	glColor4f(1,1,0.1,0.3);
	glBegin(GL_LINE_LOOP);	
	for (float i = 0 ; i < 360 ; i += 0.25) {
		glVertex2f(this->radius * cos(M_PI * i / 180) , this->radius * sin(M_PI * i / 180));
	}
	glEnd();
	glColor4f(1,1,0.1,0.3);
	glBegin(GL_LINE_LOOP);	
	for (float i = 0 ; i < 360 ; i += 0.25) {
		glVertex2f((this->radius + 0.01) * cos(M_PI * i / 180) , (this->radius + 0.01) * sin(M_PI * i / 180));
	}
	glEnd();
	glPopMatrix();
}


#endif