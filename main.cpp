using namespace std;
#include <iostream>
#include <cstring>
#include "Catalogue.h"

void initCatalogue()
{
    char* nomCatalogue = new char[5];
    strcpy(nomCatalogue,"cata1");
    Catalogue *myCatalogue = new Catalogue(nomCatalogue);
	myCatalogue->MenuCatalogue();
    delete myCatalogue;

}

int main()
{

	initCatalogue();

    return 0;
}
