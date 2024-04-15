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
    /**
     * @return renvoi le joueur du jeu
    */
    Joueur getJoueur();
    /** 
     * @return Graphe& revoie le graphe du jeu par référence
    */
    Graphe& getGraphe();
    /** 
     * @return Noeud* revoie le noeud actuel du graphe 
    */
    Noeud* getCNoeud();
    
};
#endif