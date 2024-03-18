#ifndef _JEU_H
#define _JEU_H

#include "dialogue.h"
#include "combat.h"
using namespace std; 

class Jeu{
    private:
    Noeud jeu[10];
    Joueur joueur;

    public: 
    Jeu(const string &filename);
    Joueur getJoueur();
    
};
#endif