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
     * @brief constructeur intialise de combat
     * @param eg Rempli ennGroup 
     * @param gs Taille de eg
     * @param ind Indice du noeud
    */
    Combat(Ennemi eg[MAXENNEMI], int gs, int ind, string nomN, char d);
    
    ~Combat();
    int castSort(Joueur& j, string s);
    void ennHitPlay(Joueur& j, float sort);
    void playHitEnn(Joueur& j, float degat, int tar);
    void ennTurn(Joueur& j);
    void playTurn(Joueur& j, int sort, int tar);
    int isFight(Joueur& j) const;
    void affStat(Joueur& j) const;
};


#endif
