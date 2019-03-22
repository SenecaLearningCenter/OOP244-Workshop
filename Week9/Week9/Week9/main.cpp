#include <iostream>
#include "Honda.h"
#include "Car.h"
#include "HondaSoccerVan.h"

using namespace std;

int main() {
	//demo of prefix vs postfix
	int x=1;
	int y=x++;

	cout << "Y: " << y << " X: " << x << endl;
	int z=++x;
	cout << "Z: " << z << " X: " << x << endl;

	//Virtual 

	//how can you store a honda in a car???
	//amy child can be stored in it parents pointer BUT with the limit being on its parents functions
	
	Car* honda = &Honda();///get the adddress of the new honda and store it in car pointer
	Car* hondaVan = &HondaSoccerVan();

	honda->Display();
	hondaVan->Display();//where does this line get the number of cyclders from
	return 0;
}