#ifndef _BOUNDING_BOARD_CPP
#define _BOUNDING_BOARD_CPP

#include "BoundingBoard.h"
#include <GL/glut.h>
#include <cmath>

BoundingBoard::BoundingBoard () {
	this->width = 10;
	this->height = 10;
}

BoundingBoard::~BoundingBoard () {

}

void BoundingBoard::drawSelf() {
	glPushMatrix();
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glColor4f(1,1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-width/2, -height/2); 
    glVertex2f(width/2, -height/2); 
    glVertex2f(width/2, height/2); 
    glVertex2f(-width/2, height/2); 
    glEnd();
    glColor4f(0.3,0.3,0.9,0.7); // Outer
    glBegin(GL_QUADS);
    glVertex2f(-width/2 - 0.02, -height/2 - 0.02); 
    glVertex2f(width/2 + 0.02, -height/2 - 0.02); 
    glVertex2f(width/2 + 0.02, height/2 + 0.02); 
    glVertex2f(-width/2 - 0.02, height/2 + 0.02); 
    glEnd();
    glColor4f(0.5,0.5,0.9,0.7); // Inner
    glBegin(GL_QUADS);
    glVertex2f(-width/2 + 0.02, -height/2 + 0.02); 
    glVertex2f(width/2 - 0.02, -height/2 + 0.02); 
    glVertex2f(width/2 - 0.02, height/2 - 0.02); 
    glVertex2f(-width/2 + 0.02, height/2 - 0.02); 
    glEnd();

    glColor4f(1,1,1,1);
    glBegin(GL_QUADS);
    glVertex2f(-width/2.75, -height/2.75); 
    glVertex2f(width/2.75, -height/2.75); 
    glVertex2f(width/2.75, height/2.75); 
    glVertex2f(-width/2.75, height/2.75); 
    glEnd();
    glColor4f(0.9,0.3,0.3,0.7);
    glBegin(GL_QUADS);
    glVertex2f(-width/2.75 - 0.02, -height/2.75 - 0.02); 
    glVertex2f(width/2.75 + 0.02, -height/2.75 - 0.02); 
    glVertex2f(width/2.75 + 0.02, height/2.75 + 0.02); 
    glVertex2f(-width/2.75 - 0.02, height/2.75 + 0.02); 
    glEnd();
    glColor4f(0.9,0.5,0.5,0.7);
    glBegin(GL_QUADS);
    glVertex2f(-width/2.75 + 0.02, -height/2.75 + 0.02); 
    glVertex2f(width/2.75 - 0.02, -height/2.75 + 0.02); 
    glVertex2f(width/2.75 - 0.02, height/2.75 - 0.02); 
    glVertex2f(-width/2.75 + 0.02, height/2.75 - 0.02); 
    glEnd();
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glPopMatrix();
}

bool BoundingBoard::isColliding(GenericCollidingChip chip) { 
    bool c1 = (chip.getPositionX() + chip.getRadius()) > (this->width / 2);
    bool c2 = (chip.getPositionX() - chip.getRadius()) < -(this->width / 2);
    bool c3 = (chip.getPositionY() + chip.getRadius()) > (this->height / 2);
    bool c4 = (chip.getPositionY() - chip.getRadius()) < -(this->height / 2);
	return c1 | c2 | c3 | c4;
}

#endif
