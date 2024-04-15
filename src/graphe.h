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
    /**
     * @brief renvoi la variable n qui représente le noeud actuel
     * @return Noeud*
    */
    Noeud* getNoeud();
    /**
     * @brief met n à jour en utilisant id
    */
    void parcoursGraphe(int id);
    /**
     * @brief test si le noeud actuel est une feuille
     * @return bool
    */
    bool isFeuille(Noeud* nActu);
};
#endif