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
    void initGame();
    void afficherConsole();//affichage de l'image
    
};
#endif