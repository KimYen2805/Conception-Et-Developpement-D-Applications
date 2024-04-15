// Ennemi.cpp
#include <iostream>
#include "ennemi.h"
using namespace std;

int const EMAXSORT = 10;

Ennemi::Ennemi() {
    pointDeVie = 100;
    pvMax=100;
    puissance = 20;
}

Ennemi::~Ennemi() {
    
}

int Ennemi::getPointDeVieEnnemi() const {
    return pointDeVie;
}

int Ennemi::getPVmaxEnnemi() const{
    return pvMax;
}

void Ennemi::setPointDeVieEnnemi(int points) {
    pointDeVie = points;
}

void Ennemi::setPVmaxEnnemi(int pv){
    pvMax=pv;
    pointDeVie = pvMax;
}

void Ennemi::updatePVEnn(float pv){
    if(pointDeVie>0)
    {
        if ((pointDeVie + pv) >= pvMax) pointDeVie = pvMax;

        else if((pointDeVie + pv) <= 0) pointDeVie = 0;

        else pointDeVie += pv;
    }
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

int Ennemi::getSsize(){
    return tabInd_Sort.size();
}
int Ennemi::getSort(int n){
    return tabInd_Sort[n];
}

int Ennemi::nbEnne() {

    return 2;
}

int Ennemi::posXEnne(int n) {
    return n*70; 
}

int Ennemi::posYEnne(int n) {
    return 100+(n%2)*70; 
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
