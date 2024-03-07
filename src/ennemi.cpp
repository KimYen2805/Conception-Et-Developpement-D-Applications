// Ennemi.cpp
#include "ennemi.h"

#include <iostream>

using namespace std;

Ennemi::Ennemi() {
    point_de_vie = 100;
    puissance = 20;
    tab_Sort = new Sort[10];  // un nombre de sorts fictif
}

Ennemi::~Ennemi() {
    delete[] tab_Sort;
}

int Ennemi::getPointDeVieEnnemi() const {
    return point_de_vie;
}

void Ennemi::setPointDeVieEnnemi(int points) {
    point_de_vie = points;
}

int Ennemi::getPuissanceEnnemi() const {
    return puissance;
}

void Ennemi::setPuissanceEnnemi(int pu) {
    puissance = pu;
}

void Ennemi::attaquerJoueur() {
    
}
