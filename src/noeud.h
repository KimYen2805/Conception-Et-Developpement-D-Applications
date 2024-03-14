#ifndef _NOEUD_H
#define _NOEUD_H
#include <fstream>
#include "joueur.h"

class Noeud {
private:
    int indice;
    string nomNoeud;
    Joueur joueur;

public:
    Noeud();
    void parcourirNoeud(Joueur J);

};
#endif