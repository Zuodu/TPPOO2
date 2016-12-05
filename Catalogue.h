/*************************************************************************
                           Catalogue.h  -  description
                             -------------------
    début                : 16/11/2016
    copyright            : (C) 2016 par Yohan GRACIA et Zifan YAO
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Parcours.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
//
//
//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AfficherCatalogue () const;
    void AddToCatalogueTS (TrajetSimple *unTrajet);
	void AddToCatalogueTSSaisie();
    void AddToCatalogueTC (TrajetCompose *unTrajet);
	void AddToCatalogueTCSaisie();
	bool AddToCatalogueTCFin(char* arriveeC, Parcours* premierParcours, bool trajetFini);
	void RechercheSimple();
    void RechercheAvancee();
    void MenuCatalogue ();

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    /*Catalogue ( const Catalogue & unCatalogue );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
     */

    Catalogue (char* unNom);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Catalogue ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées
    int ** MatriceAdjacenceInversee();
    char ** MatriceTrajetsInversee();
    int *** MatriceNomTrajetsInversee();
private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés
    Parcours * listeTrajets;
    char * nomCatalogue;
    int idTC;
    int idTS;
//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};
#endif //CATALOGUE_H

