/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"
//------------------------------------------------------------- Constantes
const int TCstart = 1000;
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type TrajetCompose::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void TrajetCompose::afficherTrajet() const {
	Parcours * current = listeEscales;
	cout << "| TC"<<id-TCstart<<" = ";
	while(current!=NULL)
	{
		//cout << "TrajetCompose afficher while" << endl;
		current->trajetAssocie->afficherTrajet();
        cout << " | ";
		current = current->nextParcours;
	}
    cout<<endl;
}

int TrajetCompose::getID() const{
    return id;
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*TrajetCompose::TrajetCompose ( const TrajetCompose & unTrajetCompose )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
} //----- Fin de TrajetCompose (constructeur de copie)*/


TrajetCompose::TrajetCompose (int unId,char* unDepart, char* unArrivee, Parcours* uneListeEscales)
        :Trajet(unDepart, unArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
    listeEscales = uneListeEscales;
    id = unId;
} //----- Fin de TrajetCompose


TrajetCompose::~TrajetCompose ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    delete []listeEscales;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

