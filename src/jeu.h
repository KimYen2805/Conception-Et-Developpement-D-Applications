#ifndef _JEU_H
#define _JEU_H
#include "graphe.h"

using namespace std; 
const int GSIZE=10;

class Jeu{
    private:
    Graphe jeu;
    //Noeud jeu[GSIZE];
    Joueur joueur;

public: 
    Jeu();
    Joueur getJoueur();
    
};
#endif