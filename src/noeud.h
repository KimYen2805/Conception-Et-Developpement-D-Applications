#ifndef _NOEUD_H
#define _NOEUD_H
#include <fstream>
#include "joueur.h"

class Noeud {
protected:
    int id;
    string nomNoeud;
    char delim;

public:
    Noeud();
    int getID();

};
#endif