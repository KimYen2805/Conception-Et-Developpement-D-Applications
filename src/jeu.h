#ifndef _JEU_H
#define _JEU_H
#include "graphe.h"

using namespace std; 


class Jeu{
    private:
    Graphe jeu;
    Joueur joueur;

public: 
    Jeu();
    Joueur getJoueur();

    Graphe& getGraphe();
    Noeud* getCNoeud();
    
};
#endif