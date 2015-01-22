#ifndef _PLAYER_CPP
#define _PLAYER_CPP 

#include "Player.h"

Player::Player() {
	this->score = 30;
}

Player::~Player() {

}

void Player::setScore(int score) {
	this->score = score;
}

int Player::getScore() {
	return this->score;
}

void Player::updateScore(int scoreDelta) {
	this->score += scoreDelta;
}

#endif