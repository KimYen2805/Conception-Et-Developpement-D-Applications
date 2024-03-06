#include <iostream>
#include "Joueur.h"
using namespace std; 

Joueur :: Joueur() {
    nom = "";
    pointsDeVie = 0;
    pointDeVieMax = 200;
    mana = 0;
    maxMana=  10;
    tabSort = NULL;
}

Joueur :: ~Joueur() {
    delete[] tabSort;
}
string Joueur ::getNom()const {}
int Joueur ::getPoint_de_vie() {
    return pointsDeVie;
}
void Joueur::setPoint_de_vie(int pointsDeVie) {
    
}
int Joueur ::getMana() {
    return mana;
}
void Joueur::setMana(int mana) {
}