#include "Student.h"

int main()
{
	Student s(0);
	s += 10.5;
	s += 100.40;
	s += 20.5;
	s += 78.3;
	s += 44.678;
	s += 34.6;
	s += 100.50;

	s.display();
	return 0;
}