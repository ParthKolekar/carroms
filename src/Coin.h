#ifndef _COIN_H
#define _COIN_H

#include "GenericCollidingChip.h"

class Coin : public GenericCollidingChip
{
	int type;
public:
	Coin();
	~Coin();

	void drawSelf();
	
};

#endif