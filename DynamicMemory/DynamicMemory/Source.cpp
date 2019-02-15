//This code is based on Marcel Jars Code with added notation and bonus info
//THIS CODE IS PROGRAMED TO CRASH AT SPECIFIED POINTS they are noted and commented out to start out with so the code will run the first time

//size_t is just an unsigned number that can get very big 

#include <iostream>
using namespace std;

bool runExampleOne();
void runMemoryLeak();
bool runExampleWithNoThrowAlocation(size_t allocationSize);
bool runExampleWithoutNoThrowAlocation(size_t allocationSize);


int main()
{
	runExampleOne();//not the best example but it is Marcel's one

	//runMemoryLeak();//Will crash due to memory leak

	//Run allocation with std::nothrow
	if (runExampleWithNoThrowAlocation(SIZE_MAX))
		cout << "Allocated array of size: " << SIZE_MAX << " Correctly" << endl;
	else
		cout << "Failed to Allocated array of size: " << SIZE_MAX << endl;


	//Run same allocation with no std::nothrow (will crash)

	//if (runExampleWithoutNoThrowAlocation(SIZE_MAX))
	//	cout << "Allocated array of size: " << SIZE_MAX << " Correctly" << endl;
	//else
	//	cout << "Failed to Allocated array of size: " << SIZE_MAX << endl;

	return 0;
}

//This function will return true if run correctly or false if the allocation failed
bool runExampleOne()
{
	int size;//The Size to initialize the value to
	std::cout << "Enter the size of your array" << std::endl;
	std::cin >> size;//get the size


	/*
		std::nothrow according to the documentation (http://www.cplusplus.com/reference/new/nothrow/)
		will make the pointer be a null pointer if the allocation fails. If nothrow was not included here, if your operating system
		unable to allocate enough memory your code would crash (highly unlikely). Instead with nothrow it will just return nullptr.
		This is normally not included when allocating memory but is a valid use. 

		Extra notes about the new keyword that YOU DO NOT NEED TO KNOW OR UNDERSTAND can be found at (https://en.cppreference.com/w/cpp/language/new)
		Notice the new takes placement_params in the syntax which is what nothrow is.
	*/
	char *my_array = new (std::nothrow) char[size];//allocate the array to the size of size.
	if (my_array == nullptr) {
		return false;//if memory failed to allocate due to nothrow my_array will be nullptr; so we return false.
	}
	else {
		for (int i = 0; i < size; i++) {
			std::cout << "Enter a single character: ";
			std::cin >> my_array[i];//fill in array
		}
	}
	std::cout << "You entered: " << my_array << std::endl; //print array
	delete[] my_array; //deallocating memory

	return true;
}

//Demonstrating the danger of memory leaks
void runMemoryLeak()
{
	for (size_t k = 0; k < SIZE_MAX; k++)
	{

		int size = 128;
		int *array_numbers = new int[size];
		//this will keep allocating memory till the system runs out of memory

		//delete [] array_numbers; //if you uncomment this line and set k < SIZE_MAX to a lower number i.e. 100 or 10 to lower run time this function will work
	}
	
}

//Example of used to show why nothrow might be used
bool runExampleWithNoThrowAlocation(size_t allocationSize)
{
	char *my_array = new (std::nothrow) char[allocationSize];//allocate the array to the size of size.

	bool temp= my_array != nullptr;//store if it worked

	delete[] my_array;//prevent memory leak

	return temp;//return result
}

bool runExampleWithoutNoThrowAlocation(size_t allocationSize)
{
	char *my_array = new char[allocationSize];//allocate the array to the size of size. if it is too big system will crash

	bool temp = my_array != nullptr;//store if it worked

	delete[] my_array;//prevent memory leak

	return temp;//return result
}
