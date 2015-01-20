#ifndef _POCKET_H
#define _POCKET_H

#include "GenericCollidingChip.h"

class Pocket : public GenericCollidingChip
{
	int orientation;
public:
	Pocket();
	~Pocket();

	Pocket(int,float,float);

	void setOrientation(int);
	int getOrientation();

	void drawSelf();
	bool isFullyEncompassing(GenericCollidingChip);
	
};

#endif