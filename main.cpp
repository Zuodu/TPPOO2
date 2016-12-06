using namespace std;
#include <iostream>
#include "Catalogue.h"

void initCatalogue()
{
    char* nomCatalogue = (char*) "catalogue1";
    Catalogue *myCatalogue = new Catalogue(nomCatalogue);
	myCatalogue->MenuCatalogue();
}

int main() {

	initCatalogue();

    return 0;
}
