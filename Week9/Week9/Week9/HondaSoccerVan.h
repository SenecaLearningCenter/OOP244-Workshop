#pragma once
#include "Car.h"
class HondaSoccerVan :
	public Car
{
public:
	virtual string carName();
	virtual int numberOfCylinders();
	HondaSoccerVan();
	~HondaSoccerVan();
};

