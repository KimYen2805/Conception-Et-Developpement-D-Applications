#include <iostream>
#include "joueur.h"
using namespace std; 

Joueur :: Joueur() {
    nom = "";
    pointsDeVie = 0;
    pointDeVieMax = 200;
    mana = 0;
    maxMana=  10;
    tabSort = new Sort[NBSORT]; 
}

Joueur :: ~Joueur() {
    delete[] tabSort;
}
string Joueur ::getNom()const {
    return nom; 
}
int Joueur ::getPoint_de_vie() {
    return pointsDeVie;
}
void Joueur::setPoint_de_vie(int points) {
    pointsDeVie= points; 
}
int Joueur ::getMana() {
    return mana;
}
void Joueur::setMana(int ma) {
    mana= ma ;
}