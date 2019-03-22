#pragma once
#include "Honda.h"

class HondaSoccerVan :
	public Car
{
public:
	virtual string carName();
	virtual int numberOfCylinders();
	HondaSoccerVan();
	~HondaSoccerVan();
};

