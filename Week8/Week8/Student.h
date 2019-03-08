#pragma once
#include <iostream>
using namespace std;
// Student.h

class Student {
	int maxSize;//max size of the array
	float* grade;
	int currentIndex;//current number of elements used

	//addNumberOfEl represents the number of elements to be added to the array
	void updateSize(int addNumberOfEl);

public:
	Student();
	Student(int size);
	//Student(const Student&);
	Student& operator+=(float newEl);//add a element to this array!
	//Student& operator=(const Student&);

	~Student();
	void display() const;
};

