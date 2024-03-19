#ifndef _NOEUD_H
#define _NOEUD_H
#include <fstream>
#include "joueur.h"

class Noeud {
protected:
    int indice;
    string nomNoeud;
    Joueur joueur;
    int* fils;

public:
    Noeud();
    Noeud(Joueur j);
    void parcourirNoeud(Joueur j);

};
#endif