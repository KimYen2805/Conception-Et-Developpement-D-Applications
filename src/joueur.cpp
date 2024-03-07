#include <iostream>
#include "joueur.h"
using namespace std; 


Joueur::Joueur() {

    nomJoueur = "";
    pointDeVieMax = 0;
    pointsDeVie = pointDeVieMax;
    maxMana = 0;
    mana = maxMana;
    for(int i=0; i<=NBSORT;i++)
    {
        tabSort[i] = Sort(); 
    }

    for(int i=0; i<=NBOBJ;i++)
    {
        tabObjet[i] = Objet(); 
    }  
}

Joueur :: ~Joueur() {
    delete[] tabSort;
    delete[] tabObjet;
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