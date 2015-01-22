#ifndef _GENERIC_OBJECT_H
#define _GENERIC_OBJECT_H 

class GenericObject
{
protected:
	float positionX;
	float positionY;

	float deltaX;
	float deltaY;

	float mass;

public:
	GenericObject();
	~GenericObject();
	void setPositionX(float);
	void setPositionY(float);
	void setDeltaX(float);
	void setDeltaY(float);
	void stopSelf();
	void setPosition(float,float);
	void setDelta(float,float);
	void setMass(float);

	float getPositionX();
	float getPositionY();
	float getDeltaX();
	float getDeltaY();
	float getMass();
	float getDeltaMagnitude();

	float getNextPositionX();
	float getNextPositionY();

	void moveNext();

	void updateDeltaBy(float, float);
	bool isStopped();
};

#endif