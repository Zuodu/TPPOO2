/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>
//------------------------------------------------------ Include personnel
#include "Catalogue.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Catalogue::AfficherCatalogue () const
// Algorithme :
//
{
	cout<<"affichage du catalogue "<< nomCatalogue << endl;
	listeTrajets->trajetAssocie->afficherTrajet();

	
} //----- Fin de Méthode

void Catalogue::AddToCatalogueTS (TrajetSimple *unTrajet)
{
	Parcours* currentParcours = listeTrajets;
	while(currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
	}
	currentParcours->trajetAssocie = unTrajet;
}

void Catalogue::AddToCatalogueTC (TrajetCompose *unTrajet)
{
	//TODO finir la méthode ?
	Parcours* currentParcours = listeTrajets;
	while(currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
	}
	currentParcours->trajetAssocie = unTrajet;
}

void Catalogue::MenuCatalogue () const
{
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*Catalogue::Catalogue ( const Catalogue & unCatalogue )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue (constructeur de copie)
*/

Catalogue::Catalogue (char* unNom)
// Algorithme :
//
{
	TrajetSimple* trajetInit = new TrajetSimple(unNom,unNom,unNom);
	listeTrajets = new Parcours(trajetInit);
	nomCatalogue = unNom;
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue


Catalogue::~Catalogue ( )
// Algorithme :
//
{
	//TODO  : besoin d'une boucle pour delete chaque pointeur qui suit faire dans le sens 1 vers 2 etc
	// ex : current, on va sur le premier, on prend le suivant, on delete le premier
	delete listeTrajets;
	delete[] nomCatalogue;
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

