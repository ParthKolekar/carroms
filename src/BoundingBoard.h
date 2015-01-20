#ifndef _BOUNDING_BOARD_H
#define _BOUNDING_BOARD_H 

#include "GenericObject.h"
#include "GenericCollidingChip.h"

class BoundingBoard : public GenericObject
{
	float width;
	float height;
public:
	BoundingBoard();
	~BoundingBoard();
	void drawSelf();
	bool isColliding(GenericCollidingChip);

};


#endif