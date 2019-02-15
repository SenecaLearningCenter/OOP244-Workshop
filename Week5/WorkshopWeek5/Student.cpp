// Student.cpp

#include <iostream>
#include <algorithm>

using namespace std;
#include "Student.h"

Student::Student() {
	no = 0;
	ng = 0;
}

Student::Student(int n) {
	float g[] = { 0.0f };
	*this = Student(n, g, 0,name);
}

Student::Student(int sn, const float* g, int ng_,string name) {
	this->name = name;
	bool valid = sn > 0 && g != nullptr && ng_ >= 0;
	if (valid)
		for (int i = 0; i < ng_ && valid; i++)
			valid = g[i] >= 0.0f && g[i] <= 100.0f;

	if (valid) {
		// accept the client's data
		no = sn;
		ng = ng_ < NG ? ng_ : NG;
		for (int i = 0; i < ng; i++)
			grade[i] = g[i];
	}
	else {
		*this = Student();
	}
}

void Student::display() const {
	if (no > 0) {
		cout << no << ":\n";
		cout.setf(ios::fixed);
		cout.precision(2);
		for (int i = 0; i < ng; i++) {
			cout.width(6);
			cout << grade[i] << endl;
		}
		cout.unsetf(ios::fixed);
		cout.precision(6);
		cout << name << endl;
	}
	else {
		cout << "no data available" << endl;
	}
}

const Student& Student::operator+=(float g) {
	if (no != 0 && ng < NG && g >= 0.f && g <= 100.f)
		grade[ng++] = g;
	return *this;
}

Student & Student::operator-=(char x)
{
	this->name.erase(std::remove(this->name.begin(), this->name.end(), x), this->name.end());//do not try to  understand it removes the letters given
	//<< >> 
	return *this;//current object is this, so we derf to get it and return it
}

Student operator+(const Student& student, float grade) {
	Student copy = student; // makes a copy
	copy += grade;          // calls the += operator on copy 
	return copy;            // return updated copy
}

Student operator+(float grade, const Student& student) {
	return student + grade; // calls operator+(const
							//    Student&, float)
}
//friend operator gives access to internal members (private members)
bool operator==(const Student& lhs, const Student& rhs) {
	bool same = lhs.no == rhs.no &&  lhs.ng == rhs.ng;
	for (int i = 0; i < lhs.ng && same; i++)
		same = lhs.grade[i] == rhs.grade[i];
	return same;
}

