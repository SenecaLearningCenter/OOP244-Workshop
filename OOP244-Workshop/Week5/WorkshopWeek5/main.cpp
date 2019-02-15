// Friends
// friends.cpp

#include <iostream>
#include "Student.h"
using namespace std;

void passByValue(int x);
void passByPointer(int* x);
void passByReferance(int& x);
void passByReferancePointer(int*& x);

int main() {
	//Friendship Example
	float gh[] = { 89.4f, 67.8f, 45.5f };
	Student harry(1234, gh, 3,"harry"), harry_(1234, gh, 3,"voldermort");
	harry_ += 63.7f;
	if (harry == harry_)
		cout << "are identical" << endl;
	else
		cout << "are different" << endl;


	//demo overide operator -=
	harry.display();
	(harry -= 'r')-='h';//without const I can remodify the student
	harry.display();

	//Passing by tutorial start here

	int x = 5;
	int* y=&x;

	cout << "The original: The value of x is: " << x << " With and address of: " << &x << endl;
	passByValue(x);
	passByPointer(&x);
	passByReferance(x);
	cout << "The Ref Pointer Original : The value of x is: " << *y << " With and address of: " << &y << endl;
	passByReferancePointer(y);
	cout << "The Ref Pointer Altered: The value of x is: " << *y << " With and address of: " << &y << endl;



}

void passByValue(int x)
{
	cout << "Pass By Value: The value of x is: " << x << " With and address of: " << &x << endl;
}

void passByPointer(int* x)
{
	cout << "Pass by Pointer The value of x is: " << x << " With and address of: " << &x << endl;
	x++;
}

void passByReferance(int & x)
{
	cout << "Pass by Referance The value of x is: " << x << " With and address of: " << &x << endl;
}

void passByReferancePointer(int*& x)
{
	x++;
}
