#pragma once
#include <string>
#include <iostream>

using namespace std;
class Car
{
public:
	virtual string carName() { return "Car"; };//virtual function
	virtual int numberOfCylinders() = 0;//pure virtual 
	 int numberOfDoors() {//normal function
		return 0;
	}
	void Display() {//normal function
		cout << "Car Name: " << carName() << 
			" Number of Cylinders: " << numberOfCylinders() <<
			" Number of doors: "<<numberOfDoors()<< endl;
	}
};

