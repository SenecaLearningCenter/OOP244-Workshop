// Student.h

#include <string>
const int NG = 20;
using namespace std;


class Student {
	int no;
	float grade[NG];
	int ng;
	string name;
public:
	Student();
	Student(int);
	Student(int, const float*, int, string name);
	const Student& operator+=(float);// returntype fucntionname (parameters)
	Student& operator-=(char);// returntype fucntionname (parameters)
	void display() const;
	friend bool operator==(const Student&, const Student&);
};


Student operator+(const Student&, float);
Student operator+(float, const Student&);