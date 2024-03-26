#ifndef _NOEUD_H
#define _NOEUD_H
#include <fstream>
#include "joueur.h"

class Noeud {
protected:
    int id;
    string nomNoeud;

public:
    Noeud();
    Noeud(Joueur j); 
    void parcourirNoeud(Joueur j);

};
#endif