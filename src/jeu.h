#ifndef _JEU_H
#define _JEU_H

#include "dialogue.h"
#include "combat.h"
using namespace std; 
const int GSIZE=10;

class Jeu{
    private:
    Noeud jeu[GSIZE];
    Joueur joueur;

    public: 
    Jeu();
    Joueur getJoueur();
    
};
#endif