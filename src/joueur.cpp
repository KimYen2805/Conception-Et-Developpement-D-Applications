#include <iostream>
#include "joueur.h"
using namespace std; 


Joueur::Joueur()  {

    nomJoueur = "";
    pointDeVieMax = 0;
    pointsDeVie = pointDeVieMax;
    maxMana = 0;
    mana = maxMana;
   /* for(int i=0; i<=NBSORT;i++)
    {
        tabSort[i] = Sort(); 
    }

   for(int i=0; i<=NBOBJ;i++)
    {
        tabObjet[i] = Objet(); 
    }  */
    //Je l'ai mis dans les commentaires pour qu'au 
    //moins le programme fonctionne et que nous puissions 
    //afficher quelques informations sur le joueur et les ennemis
}

Joueur::Joueur(string nom, int pvMx, int mnMx, Sort inSort, Objet inObj)  {

    nomJoueur = nom;
    pointDeVieMax = pvMx;
    pointsDeVie = pointDeVieMax;
    maxMana = mnMx;
    mana = maxMana;
   /* for(int i=0; i<=NBSORT;i++)
    {
        tabSort[i] = Sort(); 
    }

   for(int i=0; i<=NBOBJ;i++)
    {
        tabObjet[i] = Objet(); 
    }  */
    //Je l'ai mis dans les commentaires pour qu'au 
    //moins le programme fonctionne et que nous puissions 
    //afficher quelques informations sur le joueur et les ennemis
}

Joueur :: ~Joueur() {
   // delete[] tabSort;
   // delete[] tabObjet;
}
string Joueur ::getNomJoueur()const {
    return nomJoueur; 
}
int Joueur ::getPVJoueur() {
    return pointsDeVie;
}
void Joueur::setPVJoueur(int pv) {
    pointsDeVie= pv; 
}
void Joueur::updatePVJoueur(int pv){
    if ((pointsDeVie + pv) >= pointDeVieMax)
    {
        pointsDeVie = pointDeVieMax;
    }else if((pointsDeVie + pv) <= 0)
    {
        pointsDeVie = 0;
    }else pointsDeVie += pv;
}

int Joueur ::getMana() {
    return mana;
}
void Joueur::setMana(int ma) {
    mana= ma ;
}
void Joueur::updateMana(int ma){
    if ((mana + ma) >= maxMana)
    {
        mana = maxMana;
    }else if((mana + ma) <= 0)
    {
        mana = 0;
    }else mana += ma;
}

void Joueur::testRegression() {
    cout << "Exécution du test de régression pour la classe Joueur..." << endl;

    // Test 1: Vérifiez si les points de vie initiaux sont égaux à pointDeVieMax
    if (getPVJoueur() == pointDeVieMax) {
        cout << "Test 1 réussi : Les points de vie initiaux sont égaux à pointDeVieMax." << endl;
    } else {
        cout << "Test 1 échoué : Les points de vie initiaux ne sont pas égaux à pointDeVieMax." << endl;
    }

    // Test 2: Vérifiez si le mana initial est égal à maxMana
    if (getMana() == maxMana) {
        cout << "Test 2 réussi : Le mana initial est égal à maxMana." << endl;
    } else {
        cout << "Test 2 échoué : Le mana initial n'est pas égal à maxMana." << endl;
    }

    cout << "Test de régression terminé." << endl;
}