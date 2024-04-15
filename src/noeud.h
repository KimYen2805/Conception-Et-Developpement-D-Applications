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
    /**
     * @return id du noeud
    */
    int getID();
    /**
     * @return delim le charactere qui différencie les dialogue et combat
    */
    char getDelim();

};
#endif