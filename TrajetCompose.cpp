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

//----------------------------------------------------- Méthodes publiques
void TrajetCompose::afficherTrajet() const {
	Parcours * current = listeEscales;
	cout << "| TC"<<id<<" = ";
	while(current!=NULL)
	{
		//cout << "TrajetCompose afficher while" << endl;
		current->trajetAssocie->afficherTrajet();
        cout << " | ";
		current = current->nextParcours;
	}
    cout<<endl;
}


//-------------------------------------------- Constructeurs - destructeur
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

{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
    Parcours* bufferedParcours = listeEscales;
    Parcours* currentParcours = listeEscales;
    while(currentParcours != NULL){
        currentParcours = listeEscales->nextParcours;
        delete bufferedParcours->trajetAssocie;
        delete bufferedParcours;
        bufferedParcours = currentParcours;
    }
    delete bufferedParcours;
    delete currentParcours;
} //----- Fin de ~TrajetCompose


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées

