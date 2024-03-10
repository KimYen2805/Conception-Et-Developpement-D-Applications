// effet.cpp
#include "effet.h"
#include <iostream>
using namespace std; 

Effet::Effet() {
    nomEffet = "abc";  // Default value for nomEffet
    puissanceEffet = 10;
}
void Effet::setPuissanceEffet(int nvPuissance) {
    puissanceEffet = nvPuissance;
}

int Effet::getPuissanceEffet() const {
    return puissanceEffet;
}