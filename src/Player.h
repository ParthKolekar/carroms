#ifndef _PLAYER_H
#define _PLAYER_H 

class Player
{
	int score;
public:
	Player();
	~Player();

	int getScore();
	void setScore(int);
	void updateScore(int);
};

#endif