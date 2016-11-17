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
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Trajet::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
	void Trajet::afficherTrajet () const{}


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
} //----- Fin de ~Trajet


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

