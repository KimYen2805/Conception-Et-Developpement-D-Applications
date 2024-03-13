#ifndef _COMBAT_H
#define _COMBAT_H
#include "noeud.h"
#include "joueur.h"
#include "ennemi.h"
int const MAXENNEMI = 5;

class Combat : public Noeud{

private:

    Ennemi ennGroup[MAXENNEMI];

public:    
    Combat();
    ~Combat();
    void ennHitPlay(Sort sort);
    void playHitEnn(Sort sort);
    void ennTurn();
    void playTurn();
    void fight();

};


#endif