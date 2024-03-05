#include <iostream>
#include "Joueur.h"
using namespace std; 

Joueur :: Joueur() {
    nom = "";
    pointsDeVie = 100;
    mana = 0;
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