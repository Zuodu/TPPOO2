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
const int LG = 20;
const int  TCstart = 1000;
const int maxMemeTrajet = 5;
//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

void Catalogue::delete2D(char **table) {
    int nbMax = idTC-TCstart+idTS;
    for(int i=0;i<nbMax;i++){
        delete[] table[i];
    }
    delete[] table;
}

void Catalogue::delete2D(int **table) {
    int nbMax = idTC-TCstart+idTS;
    for(int i=0;i<nbMax;i++){
        delete[] table[i];
    }
    delete[] table;
}

void Catalogue::delete3D(int ***table) {
    int nbMax = idTC-TCstart+idTS;
    for(int i=0;i<nbMax;i++) {
        for (int j = 0; j < nbMax; j++) {
            delete[] table[i][j];
        }
        delete[] table[i];
    }
    delete[] table;
}

void Catalogue::AfficherCatalogue () const
// Algorithme :
//
{
    cout <<"--------------------------------------------"<<endl;
	cout<<"Affichage du catalogue : "<< nomCatalogue << endl;
    cout <<"--------------------------------------------"<<endl;
	bool cataVide=true;
	Parcours* currentParcours = listeTrajets;
	while (currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
		currentParcours->trajetAssocie->afficherTrajet();
		cataVide = false;
	}
	if(cataVide)
	{
		cout << "La catalogue est vide" << endl;
	}
    cout <<"--------------------------------------------"<<endl;
    cout <<"--------------FIN DU CATALOGUE--------------"<<endl;
} //----- Fin de Méthode

void Catalogue::AddToCatalogue (Trajet *unTrajet)
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
	char unDepart[LG];
	char uneArrivee[LG];
	char unTransport[LG];
    cout << "entree de TS"<<idTS<<" :"<<endl;
	cout << "Donnez la ville de depart" << endl;
	cin >> unDepart;
	cout << "Donnez la ville d'arrivee" << endl;
	cin >> uneArrivee;
	cout << "Donnez le moyen de transport" << endl;
	cin >> unTransport;
	char * depart = new char[strlen(unDepart)]; //ajustement taille chaines de caractères
	char * arrivee = new char[strlen(uneArrivee)];
	char * transport = new char[strlen(unTransport)];

    //copie des attributs
	strcpy(depart, unDepart);
	strcpy(arrivee, uneArrivee);
	strcpy(transport, unTransport);

	TrajetSimple *unTrajet = new TrajetSimple(idTS,depart, arrivee, transport);
	AddToCatalogue(unTrajet);
    idTS++;
}

void Catalogue::AddToCatalogueTCSaisie()
{
	char unDepartC[LG];
	char uneArriveeC[LG];
	char uneArrivee[LG];
	char unTransport[LG];
    cout << "entree de TC"<<idTC-TCstart<<" :"<<endl;
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

    //copie des attributs
	strcpy(depart, unDepartC);
	strcpy(arrivee, uneArrivee);
	strcpy(arriveeC, uneArriveeC);
	strcpy(transport, unTransport);
	TrajetSimple *unTrajet = new TrajetSimple(0,depart, arrivee, transport);
	Parcours * premierParcours = new Parcours(unTrajet);
	TrajetCompose * unTrajetCompose = new TrajetCompose(idTC,depart, arriveeC, premierParcours);
	AddToCatalogue(unTrajetCompose);
	bool trajetFini = false;
	while (!trajetFini)
	{
		trajetFini=AddToCatalogueTCFin(arriveeC,premierParcours);
	}
    idTC++;
}

bool Catalogue::AddToCatalogueTCFin(char* arriveeC, Parcours* premierParcours)
{
	char unDepart[LG];
	char uneArrivee[LG];
	char unTransport[LG];
    bool trajetFini = false;
	cout << "Donnez la ville de depart de votre trajet intermediaire" << endl;
	cin >> unDepart;
	cout << "Donnez la ville d'arrivee de votre trajet intermediaire" << endl;
	cin >> uneArrivee;
	cout << "Donnez le moyen de transport de votre trajet intermediaire" << endl;
	cin >> unTransport;
	char * depart = new char[strlen(unDepart)];   //ajustement taille chaines de caractères
	char * arrivee = new char[strlen(uneArrivee)];
	char * transport = new char[strlen(unTransport)];
	strcpy(depart, unDepart);
	strcpy(arrivee, uneArrivee);
	strcpy(transport, unTransport);
	TrajetSimple *unTrajetSimple = new TrajetSimple(0,depart, arrivee, transport);
	Parcours * unParcours = new Parcours(unTrajetSimple);

	Parcours* currentParcours = premierParcours;
	while (currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
	}
	currentParcours->nextParcours = unParcours;
	if (strcmp(arriveeC, arrivee)==0) 
	{
		trajetFini = true;
	}
	return trajetFini;
}

bool Catalogue::ligneVide(int index,int** matrixAdj,int nbMax) {
    for(int i =0;i<nbMax;i++){
        if(matrixAdj[index][i]==1){
            return false;
        }
    }
    return true;
}

int*** Catalogue::RechercheGraphe(char *depart,char *arrivee,int **matrixAdj,int ***matrixIdAdj,char **matrixNodeAdj, int*** solutions,int nbMax) {
    int indexParcouru[nbMax];
    int departIndex = 0,arriveeIndex = 0;
    int currentDepartIndex =0;
    int lastDepartIndex = 0;
    int i,j,k,l;
    int ic = 0;
    int c = 0,t = 0;
    bool over = false;
    //init des indexs : on les situe selon le depart et l'arrivee désirés
    for(i=0;i<nbMax;i++){
        if(strcmp(matrixNodeAdj[i],depart)==0){
            arriveeIndex = i;
        }
        if(strcmp(matrixNodeAdj[i],arrivee)==0){
            departIndex = i;
            currentDepartIndex = i;
            for(l=0;l<nbMax;l++){
                indexParcouru[l] = i;
            }
            ic++;
        }
    }

    //recherche des trajets par profondeur
    while(!over){
        for(j=0;matrixAdj[currentDepartIndex][j]!=1 && j<nbMax;j++){}//je me déplace dans la ligne et je m'arrete au premier 1 rencontré

            if(j == arriveeIndex){//si le 1 se trouve dans la colonne de l'arrivee
                    solutions[c][t] = matrixIdAdj[currentDepartIndex][j];//j'enregistre l'id du trajet dans ma matrice solution
                    c++;// je change de ligne de solution (solution complète)
                    t=0;//je remet le premier trajet à 0
                matrixAdj[currentDepartIndex][j] = 0;//je considère que le trajet a disparu
                //je reviens au début du while
                }else{
                if (!ligneVide(j, matrixAdj,nbMax)) {//si la ligne suivante n'est pas vide,
                    solutions[c][t] = matrixIdAdj[currentDepartIndex][j];
                    t++;//j'enregistre le trajet à la suite,
                    matrixAdj[currentDepartIndex][j] = 0;
                    lastDepartIndex = currentDepartIndex;
                    currentDepartIndex = j;// je change de ligne et j'enregistre la derniere ligne
                    indexParcouru[ic] = j;
                    ic++;// je dit que j'ai utilisé cette ligne
                } else {
                    matrixAdj[currentDepartIndex][j] = 0;//si la ligne suivante est vide, je supprime ce trajet

                }
                //FIND DU DEUXIEME IF

                }//FIN DU PREMIER IF
        over = true;
        for(i=0;i<nbMax;i++){
            over = ligneVide(indexParcouru[i],matrixAdj,nbMax);
        }
        // a confirmer que c'est necessaire
        if(j == nbMax-1 && currentDepartIndex == departIndex){over = true;}

    }
    return solutions;
}

void Catalogue::AfficherSolution(int *** solutions) {
    int nbMax = idTC-TCstart+idTS;
    cout<<"disp d'une solution de trajet"<<endl;
    for(int i=0;i<nbMax;i++){
        cout <<solutions[0][i][0]<<endl;
    }
}

void Catalogue::RechercheSimple() 
{
	char unDepart[LG];
	char uneArrivee[LG];
	cout << "Donnez la ville de depart qui vous interesse:" << endl;
	cin >> unDepart;
	cout << "Donnez la ville d'arrivee qui vous interesse:" << endl;
	cin >> uneArrivee;
	char * departRecherche = new char[strlen(unDepart)];   //ajustement taille chaines de caractères
	char * arriveeRecherche = new char[strlen(uneArrivee)];
	strcpy(departRecherche, unDepart);
	strcpy(arriveeRecherche, uneArrivee);
	Parcours* currentParcours = listeTrajets;
	bool estEgal = false;
	bool auMoinsUn = false;
	while (currentParcours->nextParcours != NULL)
	{
		currentParcours = currentParcours->nextParcours;
		estEgal = currentParcours->trajetAssocie->comparerTrajet(departRecherche, arriveeRecherche);
		if (estEgal)
		{
			auMoinsUn = true;
			currentParcours->trajetAssocie->afficherTrajet();
		}
	}
	if (!auMoinsUn)
	{
		cout << "Aucun trajet du catalogue ne correspond a votre recherche" << endl;
	}
}

void Catalogue::RechercheAvancee()
{
    char *rechercheDepart = new char[LG];
    char *rechercheArrivee = new char[LG];
    int currentRow = 0;
    int currentDoublon = 0;
    int departIndex = 0;
    int arriveeIndex = 0;
    bool existeInMatRow = false;
    int nbMax = idTC-TCstart+idTS;
    int*** solutions = MatriceNomTrajetsInversee();
    int ** matrixInv = MatriceAdjacenceInversee();
    char** matrixTrjInv = MatriceTrajetsInversee();
    int *** matrixIdInv = MatriceNomTrajetsInversee();
    Parcours* currentParcours = listeTrajets;
    while (currentParcours->nextParcours != NULL){
    //chaque trajet est traite et mis dans les differentes matrices
        //on saute le premier qui est un init
        currentParcours = currentParcours->nextParcours;
        //traitement de l'arrivee
        for(int i=0;i<nbMax;i++){
            if(currentParcours->trajetAssocie->comparerArrivee(matrixTrjInv[i])){
                existeInMatRow = true;
            }
        }
        if(!existeInMatRow){
            matrixTrjInv[currentRow] = currentParcours->trajetAssocie->getArrivee();
            currentRow++;
            existeInMatRow = false;
        }

        //traitement du depart
        for(int j=0;j<nbMax;j++) {
            if (currentParcours->trajetAssocie->comparerDepart(matrixTrjInv[j])) {
                existeInMatRow = true;
                departIndex = j;
            }
        }

        if(!existeInMatRow){
            matrixTrjInv[currentRow] = currentParcours->trajetAssocie->getDepart();
            existeInMatRow = false;
            matrixInv[currentRow-1][currentRow] = 1;
            matrixIdInv[currentRow-1][currentRow][currentDoublon] = currentParcours->trajetAssocie->getID();
            currentRow++;
        }
        if(existeInMatRow){  // si sa ligne existe deja
            for(int k=0;k<nbMax;k++) {
                if (currentParcours->trajetAssocie->comparerArrivee(matrixTrjInv[k])) {
                        arriveeIndex = k; // on cherche l'index de l'arrivee
                }
            }
            matrixInv[arriveeIndex][departIndex] = 1; // on indique le trajet exsite
            while(matrixIdInv[arriveeIndex][departIndex][currentDoublon]!=0) {
                currentDoublon++;
            } //on cherche la derniere case vide des id deja parcourus qui correspondent au meme trajet en gros
            matrixIdInv[arriveeIndex][departIndex][currentDoublon] = currentParcours->trajetAssocie->getID();
            // on insere l'id du trajet actuel
        }
        // on reinitialise les doublons
        currentDoublon = 0;
        existeInMatRow = false;
        // on va au prochain trajet
    }//FIN DU WHILE
    //cout<<matrixIdInv[3][2][0]<<"id"<<endl;

    //input de la recherche
    cout<<"Choisissez la ville de depart"<<endl;
    cin >>rechercheDepart;
    cout<<"Choisissez la ville d'arrivee"<<endl;
    cin >>rechercheArrivee;

    //calcul des solutions et affichage

    solutions = RechercheGraphe(rechercheDepart,rechercheArrivee,matrixInv,matrixIdInv,matrixTrjInv,solutions,nbMax);
    AfficherSolution(solutions);

    //delete
    delete[] rechercheArrivee;
    delete[] rechercheDepart;
    //delete2D(matrixTrjInv);
    //delete2D(matrixInv);
    //delete3D(solutions);
    //delete3D(matrixIdInv);

}

void Catalogue::MenuCatalogue ()
{
	bool sortie =false;
	int choix =0;
	while(!sortie)
	{
		cout<<"Choisissez une operation:"<<endl;
		cout<<"1: Afficher le catalogue"<<endl;
		cout<<"2: Ajouter un trajet simple"<<endl;
		cout<<"3: Ajouter un trajet compose"<<endl;
		cout<<"4: Faire une recherche simple de parcours"<<endl;
		cout<<"5: Faire une recherche avancee de parcours" << endl;
		cout<<"6: Quitter le catalogue"<<endl;
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
			break;
			case 4:
				RechercheSimple();
			break;
			case 5:
				RechercheAvancee();
			break;
			case 6:
				sortie = true;
			break;
			default:
			cout<<"Cette option n'est pas dans le catalogue"<<endl;
		}
	}
}
//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue (char * unNom)
// Algorithme :
//
{
	TrajetSimple* trajetInit = new TrajetSimple(0,unNom,unNom,unNom);
	listeTrajets = new Parcours(trajetInit);
	nomCatalogue = unNom;
    idTC = TCstart+1;
    idTS = 1;
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
}


//----- Fin de ~Catalogue


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
int** Catalogue::MatriceAdjacenceInversee()
{
    int nbMax = idTC-1000+idTS;
    int** matrixAdj = new int*[nbMax];
    for(int i = 0;i<nbMax;i++){
        matrixAdj[i] = new int[nbMax];
    }
    for(int i = 0;i<nbMax;i++){
        for(int j=0;j<nbMax;j++){
            matrixAdj[i][j] = 0;
        }
    }

    return matrixAdj;
}

char **Catalogue::MatriceTrajetsInversee() {
    int nbMax = idTC-1000+idTS;
    char ** matriceTrj = new char*[nbMax];
    for(int i = 0;i<nbMax;i++){
        matriceTrj[i] = new char[LG];
    }
    return matriceTrj;
}

int ***Catalogue::MatriceNomTrajetsInversee() {
    int nbMax = idTC-1000+idTS;
    int*** matrixAdj = new int**[nbMax];
    for(int a = 0;a<nbMax;a++){
        matrixAdj[a] = new int*[nbMax];
        for(int b =0;b<nbMax;b++){
            matrixAdj[a][b] = new int[maxMemeTrajet];
        }
    }
    for(int i = 0;i<nbMax;i++){
        for(int j=0;j<nbMax;j++) {
            for (int k = 0; k < maxMemeTrajet; k++) {
                matrixAdj[i][j][k] = 0;
            }
        }
    }

    return matrixAdj;
}





//------------------------------------------------------- Méthodes privées

