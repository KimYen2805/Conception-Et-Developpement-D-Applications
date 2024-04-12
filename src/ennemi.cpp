// Ennemi.cpp
#include <iostream>
#include "ennemi.h"
using namespace std;

int const EMAXSORT = 10;

Ennemi::Ennemi() {
    pointDeVie = 100;
    puissance = 20;
}

Ennemi::~Ennemi() {
    
}

int Ennemi::getPointDeVieEnnemi() const {
    return pointDeVie;
}

void Ennemi::setPointDeVieEnnemi(int points) {
    pointDeVie = points;
}

void Ennemi::updatePVEnn(int pv){
    if(pointDeVie + pv <= 0)
    {
        pointDeVie = 0;
    }else{ pointDeVie += pv;}
}

int Ennemi::getPuissanceEnnemi() const {
    return puissance;
}

void Ennemi::setPuissanceEnnemi(int pu) {
    puissance = pu;
}

void Ennemi::addSort(int sort){
    tabInd_Sort.push_back(sort);
}

int Ennemi::nbEnne() {
    return rand() % 5 + 1; // Random number 
}

int Ennemi::posXEnne(int n) {
    return n*70; // Random X position
}

int Ennemi::posYEnne(int n) {
    return 100+(n%2)*70; // Random Y position (assuming screen height of 24 lines)
>>>>>>> refs/remotes/origin/main
}
void Ennemi::testRegression() {
    cout << "Exécution du test de régression pour la classe Ennemi..." << endl;

    // Test 1: Vérifiez si les points de vie initiaux sont égaux à 100
    if (getPointDeVieEnnemi() == 100) {
        cout << "Test 1 réussi : Les points de vie initiaux sont égaux à 100." << endl;
    } else {
        cout << "Test 1 échoué : Les points de vie initiaux ne sont pas égaux à 100." << endl;
    }

    // Test 2: Vérifiez si la puissance initiale est égale à 20
    if (getPuissanceEnnemi() == 20) {
        cout << "Test 2 réussi : La puissance initiale est égale à 20." << endl;
    } else {
        cout << "Test 2 échoué : La puissance initiale n'est pas égale à 20." << endl;
    }

    cout << "Test de régression terminé." << endl;
}
