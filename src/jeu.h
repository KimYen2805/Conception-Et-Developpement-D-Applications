#ifndef _JEU_H
#define _JEU_H

#include "dialogue.h"
#include "combat.h"
using namespace std; 

class Jeu{
    private:
    Noeud jeu;
    Joueur joueur;

    public: 
    Jeu(const string &filename);
    
};
#endif