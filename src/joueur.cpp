#include <iostream>
#include "joueur.h"
using namespace std; 


Joueur::Joueur()  {

    nomJoueur = "abc";
    pointDeVieMax = 100;
    pointsDeVie = pointDeVieMax;
    maxMana = 20;
    mana = maxMana;
   /* for(int i=0; i<=NBSORT;i++)
    {
        tabSort[i] = Sort(); 
    }

   for(int i=0; i<=NBOBJ;i++)
    {
        tabObjet[i] = Objet(); 
    }  */
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
int Joueur ::getMana() {
    return mana;
}
void Joueur::setMana(int ma) {
    mana= ma ;
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