// objet.cpp
#include <iostream>
#include "objet.h"
#include <string>
using namespace std;


Objet::Objet() :effetObjet() {
    nomObjet = "abc";
    quantite = 0; 
}

void Objet::setNomObjet(string nom) {
    nomObjet = nom;
}

void Objet::setQuantite(int nvQuantite) {
    quantite = nvQuantite;
}

void Objet::setEffetObjet(int nvPuissance) {
    effetObjet.setPuissanceEffet(nvPuissance);
}

string Objet::getNom() const {
    return nomObjet;
}

int Objet::getCoutMana() const {
    return quantite;
}

int Objet::getPuissance() const {
    return effetObjet.getPuissanceEffet();
}
