/*************************************************************************
                           Trajet.cpp  -  description
                             -------------------
    début                : 16/11/2016
    copyright            : (C) 2016 par Yohan GRACIA et Zifan YAO  
    e-mail               : 
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------
//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
using namespace std;
#include "Trajet.h"
#include <iostream>
#include <cstring>

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Trajet::afficherTrajet () const{}

bool Trajet::comparerTrajet(char* unDepart, char * uneArrivee) const
{
    bool correspond = false;
    if (strcmp(unDepart, depart) == 0 && strcmp(uneArrivee, arrivee) == 0)
    {
        correspond = true;
    }
    return correspond;
}

bool Trajet::comparerArrivee(char *uneArrivee) const{
    return strcmp(uneArrivee, arrivee) == 0;
}

bool Trajet::comparerDepart(char *unDepart) const{
    return strcmp(unDepart, depart) == 0;
}

char *Trajet::getArrivee() const{
    return arrivee;
}

char *Trajet::getDepart() const{
    return depart;
}

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
/*Trajet::Trajet ( const Trajet & unTrajet )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Trajet>" << endl;
#endif
} //----- Fin de Trajet (constructeur de copie)
*/

Trajet::Trajet (char* unDepart, char* unArrivee)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
	depart = unDepart;
	arrivee = unArrivee;
} //----- Fin de Trajet


Trajet::~Trajet ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
	delete []depart;
	delete []arrivee;
}






//----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

