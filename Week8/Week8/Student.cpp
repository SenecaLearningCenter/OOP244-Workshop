// Student.cpp

#include <iostream>
using namespace std;
#include "Student.h"

// ...

void Student::updateSize(int addNumberOfEl)
{
	float* temp= new float[maxSize + addNumberOfEl];
	
	for (int i = 0; i < currentIndex; i++)
		temp[i] = grade[i];
	
	delete[] grade;
	grade = temp;
	maxSize = maxSize + addNumberOfEl;
}

Student::Student()
{
	maxSize = 0;
	grade = nullptr;
	currentIndex = 0;
}

Student::Student(int size)
{
	grade = new float[size];
	maxSize = size;
	currentIndex = 0;
}


Student& Student::operator+=(float newEl)
{
	if (currentIndex == maxSize)
		updateSize(5);

	grade[currentIndex] = newEl;
	currentIndex++;
	return *this;
}

Student::~Student()
{
	delete[] grade;
}

void Student::display() const
{
	for (int i = 0; i < currentIndex; i++)
		cout << "Grade: " << grade[i] << endl;
}


