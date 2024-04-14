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
    int castSortSDL(Joueur& j, string s, vector<string>& lignes);
    void ennHitPlay(Joueur& j, float sort);
    void playHitEnn(Joueur& j, float degat, int tar);
    void ennTurn();
    void playTurn(Joueur& j, int sort, int tar);
    void playTurnSDL(Joueur& j, int sort, int tar, vector<string>& lignesSort);
    int isFight(Joueur& j);
    void affStat(Joueur& j);
    void affStatSDL(Joueur& j, vector<string>& lignes);
};


#endif
