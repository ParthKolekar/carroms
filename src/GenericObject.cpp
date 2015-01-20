#ifndef _GENERIC_OBECT_CPP
#define _GENERIC_OBECT_CPP

#include "GenericObject.h"
#include <cmath>

GenericObject::GenericObject () {
	// Default is stationary centered
	this->positionX = 0;
	this->positionY = 0;
	this->deltaX = 0;
	this->deltaY = 0;
	this->mass = 1e10;
}

GenericObject::~GenericObject() {

}

void GenericObject::setPositionX(float position) {
	this->positionX = position;
}

void GenericObject::setPositionY(float position) {
	this->positionY = position;
}

void GenericObject::setDeltaX(float delta) {
	this->deltaX = delta;
}

void GenericObject::setDeltaY(float delta) {
	this->deltaY = delta;
}

void GenericObject::stopObject() {
	this->deltaX = 0;
	this->deltaY = 0;
}

void GenericObject::setPosition(float positionX, float positionY) {
	this->positionX = positionX;
	this->positionY = positionY;
}

void GenericObject::setDelta(float deltaX, float deltaY) {
	this->deltaX = deltaX;
	this->deltaY = deltaY;
}

float GenericObject::getPositionX() {
	return this->positionX;
}

float GenericObject::getPositionY() {
	return this->positionY;
}

float GenericObject::getDeltaX() {
	return this->deltaX;
}

float GenericObject::getDeltaY() {
	return this->deltaY;
}

float GenericObject::getNextPositionX() {
	return this->positionX + this->deltaX;
}

float GenericObject::getNextPositionY() {
	return this->positionY + this->deltaY;
}

void GenericObject::moveNext() {
	this->positionX = this->positionX + this->deltaX;
	this->positionY = this->positionY + this->deltaY;
}

void GenericObject::setMass(float mass) {
	this->mass = mass;
}

float GenericObject::getMass() {
	return this->mass;
}

void GenericObject::updateDeltaBy(float deltaX, float deltaY) {
	this->deltaX = this->deltaX + deltaX;
	this->deltaY = this->deltaY + deltaY;
}

#endif
