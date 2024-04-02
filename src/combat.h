#ifndef _COMBAT_H
#define _COMBAT_H
#include "noeud.h"

#include "ennemi.h"
int const MAXENNEMI = 5;

class Combat : public Noeud{

private:
    vector<Ennemi> ennGroup;

public:    
    Combat();
    /**
     * @brief
     * @param eg Rempli ennGroup 
     * @param gs Taille de eg
     * @param ind Indice du noeud
    */
    Combat(Ennemi eg[MAXENNEMI], int gs, int ind, string nomN, char d);
    
    ~Combat();
    int castSort(Joueur& j, string s);
    void ennHitPlay(Sort sort);
    void playHitEnn(Sort sort);
    void ennTurn();
    void playTurn();
    void fight(Joueur& j);
};


#endif