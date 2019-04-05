#include <iostream>
#include <string>

using namespace std;

template <typename T>
T const& Max(T const& a, T const& b) {
	return a < b ? b : a;
}

template<typename T,typename K>
class test
{
public:
	T x;
	K y;
	void print()
	{
		
		cout << x <<y<< endl;
	}
};

int main() {


	test<int,string> t;
	t.y = "Test";
	t.x = 10;
	t.print();

	test<double,int> t;
	t.x = 22.5;
	t.y = 10;
	t.print();

	return 0;
}