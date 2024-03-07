#include <iostream>
#include "joueur.h"
using namespace std; 

Joueur :: Joueur() {
    nomJoueur = "";
    pointsDeVie = 100;
    pointDeVieMax = 200;
    mana = 0;
    maxMana=  10;
    tabSort = new Sort[NBSORT]; 
}

Joueur :: ~Joueur() {
    delete[] tabSort;
}
string Joueur ::getNomJoueur()const {
    return nomJoueur; 
}
int Joueur ::getPoint_de_vie_Joueur() {
    return pointsDeVie;
}
void Joueur::setPoint_de_vie_Jouer(int points) {
    pointsDeVie= points; 
}
int Joueur ::getMana() {
    return mana;
}
void Joueur::setMana(int ma) {
    mana= ma ;
}