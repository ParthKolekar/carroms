#ifndef _COIN_H
#define _COIN_H

#include "GenericCollidingChip.h"

class Coin : public GenericCollidingChip
{
	int type;
	bool pocketed;
public:
	Coin();
	~Coin();
	Coin(int,float, float);

	void setType(int);
	int getType();
	
	void drawSelf();
	int getScore();

	bool isPocketed();
	void pocketSelf();
};

#endif