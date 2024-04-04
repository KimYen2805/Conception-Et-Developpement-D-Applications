#ifndef _GRAPHE_H
#define _GRAPHE_H
#include <vector>
#include "dialogue.h"
#include "combat.h"
using namespace std;

class Graphe{
private:
    Noeud* n;
    vector<Noeud*> sommets;
    vector<pair<Noeud*,Noeud*>> aretes;

public:

    Graphe();
    ~Graphe();
    Noeud* getNoeud();
    void parcoursGraphe(int n);
    bool isFeuille(Noeud* nActu);
};
#endif