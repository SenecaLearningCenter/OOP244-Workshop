
#pragma once
#include "Car.h"

class Honda : public Car
{
public:
	virtual string carName();
	virtual int numberOfCylinders();
	int numberOfDoors();
	Honda();
	~Honda();
};

