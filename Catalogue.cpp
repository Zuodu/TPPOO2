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
	cout<<"Affichage du catalogue : "<< nomCatalogue << endl;
	bool cataVide=true;
	Parcours* currentParcours = listeTrajets;
	while (currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
		currentParcours->trajetAssocie->afficherTrajet();
		cataVide = false;
	}
	if(cataVide ==true)
	{
		cout << "La catalogue est vide" << endl;
	}
} //----- Fin de Méthode

void Catalogue::AddToCatalogueTS (TrajetSimple *unTrajet)
{
	Parcours* currentParcours = listeTrajets;
	while(currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
	}
	Parcours *nouveauParcours = new Parcours(unTrajet);
	currentParcours->nextParcours = nouveauParcours;
}
void Catalogue::AddToCatalogueTSSaisie()
{
	char unDepart[20];
	char uneArrivee[20];
	char unTransport[20];
	cout << "Donnez la ville de depart" << endl;
	cin >> unDepart;
	cout << "Donnez la ville d'arrivee" << endl;
	cin >> uneArrivee;
	cout << "Donnez le moyen de transport" << endl;
	cin >> unTransport;
	char * depart = new char[strlen(unDepart)]; //ajustement taille chaines de caractères
	char * arrivee = new char[strlen(uneArrivee)];
	char * transport = new char[strlen(unTransport)];
	strcpy(depart, unDepart);
	strcpy(arrivee, uneArrivee);
	strcpy(transport, unTransport);
	TrajetSimple *unTrajet = new TrajetSimple(depart, arrivee, transport);
	AddToCatalogueTS(unTrajet);
}

void Catalogue::AddToCatalogueTC (TrajetCompose *unTrajet)
{
	//TODO finir la méthode ?
	Parcours* currentParcours = listeTrajets;
	while(currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
	}
	Parcours *nouveauParcours = new Parcours(unTrajet);
	currentParcours->nextParcours = nouveauParcours ;
}

void Catalogue::AddToCatalogueTCSaisie()
{
	char unDepartC[20];
	char uneArriveeC[20];
	char uneArrivee[20];
	char unTransport[20];
	cout << "Donnez la ville de depart du trajet compose" << endl;
	cin >> unDepartC;
	cout << "Donnez la ville d'arrivee du trajet compose" << endl;
	cin >> uneArriveeC;
	cout << "Donnez la ville d'arrivee du premier trajet simple" << endl;
	cin >> uneArrivee;
	cout << "Donnez le moyen de transport du premier trajet simple" << endl;
	cin >> unTransport;
	char * depart = new char[strlen(unDepartC)];   //ajustement taille chaines de caractères
	char * arrivee = new char[strlen(uneArrivee)];
	char * arriveeC = new char[strlen(uneArriveeC)];
	char * transport = new char[strlen(unTransport)];
	strcpy(depart, unDepartC);
	strcpy(arrivee, uneArrivee);
	strcpy(arriveeC, uneArriveeC);
	strcpy(transport, unTransport);
	TrajetSimple *unTrajet = new TrajetSimple(depart, arrivee, transport);
	Parcours * premierParcours = new Parcours(unTrajet);
	TrajetCompose * unTrajetCompose = new TrajetCompose(depart, arriveeC, premierParcours);
	bool premierPassage = false;
	do
	{
		cout << "Donnez la ville de depart du trajet simple" << endl;
		cin >> unDepartC;
		char * depart = new char[strlen(unDepartC)];
		strcpy(depart, unDepartC);
		if(strcmp(depart, arrivee) == 0)
		{
		cout << "Donnez la ville d'arrivee du trajet simple" << endl;
		cin >> uneArrivee;
		cout << "Donnez le moyen de transport du trajet simple" << endl;
		cin >> unTransport;
		char * arrivee = new char[strlen(uneArrivee)];   //ajustement taille chaines de caractères
		char * transport = new char[strlen(unTransport)];
		strcpy(arrivee, uneArrivee);
		strcpy(transport, unTransport);
		TrajetSimple *unTrajet = new TrajetSimple(depart, arrivee, transport);
		Parcours * unParcours = new Parcours(unTrajet);
		premierParcours->nextParcours = unParcours;
		premierParcours = unParcours;
		premierPassage = true;
		}
		else
		{
			cout << "Vous n'avez pas choisi votre precedente arrivee comme nouveau depart" << endl;
		}
	} while (strcmp(arriveeC, arrivee) != 0 || premierPassage == false);
	AddToCatalogueTC(unTrajetCompose);
}

void Catalogue::MenuCatalogue ()
{
	bool sortie =false;
	int choix =0;
	while(sortie == false)
	{
		cout<<"Choisissez une operation:"<<endl;
		cout<<"1: Afficher le catalogue"<<endl;
		cout<<"2: Ajouter un trajet simple"<<endl;
		cout<<"3: Ajouter un trajet compose"<<endl;
		cout<<"4: Faire une recherche de parcours"<<endl;
		cout<<"5: Quitter le catalogue"<<endl;
		cin >> choix;
		switch (choix)
		{
			case 1:
				AfficherCatalogue();
			break;
			case 2:
				AddToCatalogueTSSaisie();
			break;
			case 3:
				AddToCatalogueTCSaisie();
				//TODO AddTrajetCompose
			break;
			case 4:
				//TODO Recherche
			break;
			case 5:
				sortie = true;
			break;
			default:
			cout<<"Cette option n'est pas dans le catalogue"<<endl;
		}
	}
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

Catalogue::Catalogue (char * unNom)
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

