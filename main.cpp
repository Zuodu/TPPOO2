using namespace std;
#include <iostream>
#include <cstring>
//#include "TrajetSimple.h"
//#include "TrajetCompose.h"
#include "Catalogue.h"


void testTrajetSimple()
{
	char* depart = new char [10];
	char* arrivee = new char [10];
	depart[0] = 'P';
	arrivee = strcpy(arrivee, depart);
	char* transport = new char [3];
	transport[0] = 'C';
	transport[1] = 'A';
	transport[2] = 'R';
	TrajetSimple* TS1 = new TrajetSimple (depart,arrivee,transport);
	TS1->afficherTrajet();
}

void testTrajetCompose()
{
    char* nomCatalogue = (char*) "katarina";
    Catalogue *myCatalogue = new Catalogue(nomCatalogue);
	myCatalogue->MenuCatalogue();
}

int main() {
  /*  std::cout << "Phase de test testAfficherCatalogue" << std::endl;
    char depart[10];
    strcpy(depart,"paris");
    char arrivee[10];
    strcpy(arrivee,"marseille");
    char transport[10];
    strcpy(transport,"car");
    char nomCatalogue[10];
    strcpy(nomCatalogue,"katakata");
    TrajetSimple *TS1 = new TrajetSimple (depart, arrivee, transport);
    Catalogue myCatalogue = Catalogue(nomCatalogue);
    myCatalogue.AddToCatalogueTS(TS1);
    myCatalogue.AfficherCatalogue();
    delete TS1;*/
	testTrajetCompose();

    return 0;
}
