// effet.cpp
#include "effet.h"
#include <iostream>
using namespace std; 

Effet::Effet() {
    nomEffet = "degatMana";  // Default value for nomEffet
    puissanceEffet = 9;
}

void Effet::setNomEffet(string nvNom){
    nomEffet=nvNom;
}

void Effet::setPuissanceEffet(float nvPuissance) {
    puissanceEffet = nvPuissance;
}

string Effet::getNomEffet() const {
    return nomEffet;
}

float Effet::getPuissanceEffet() const {
    return puissanceEffet;
}


