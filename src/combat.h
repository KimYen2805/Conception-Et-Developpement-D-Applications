#ifndef _COMBAT_H
#define _COMBAT_H
#include "noeud.h"

#include "ennemi.h"
#include <sstream>
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
    /**
     * @brief test si le s rentré par le joueur est valide
     * @param j le joueur du jeu en cours
     * @param s sort entré par le joueur 
     * @return -1 si s n'est pas un sort valide, sinon l'indice de s
    */
    int castSort(Joueur& j, string s);
    /**
     * @brief identique à castSort
     * 
    */
    int castSortSDL(Joueur& j, string s, vector<string>& lignes);
    /**
     * @brief reduit la vie du joueur avec sort
     * @param j le joueur du jeu en cours
     * @param sort dégâts infligé au joueur
    */
    void ennHitPlay(Joueur& j, float sort);
    /**
     * @brief reduit la vie de l'ennemi à l'indice tar avec sort
     * @param j le joueur du jeu en cours
     * @param sort dégâts infligé au joueur
     * @param tar indice de l'ennemi dans ennGroup, si tar = 0 attaque un ennemi aléatoire
    */
    void playHitEnn(Joueur& j, float degat, int tar);
    /**
     * @brief toutes les actions liées aux tour ennemi
     * @param j le joueur du jeu en cours
    */
    void ennTurn(Joueur& j);
    /**
     * @brief toutes les actions liées au actions du joueur
     * @param j le joueur du jeu en cours
     * @param sort l'indice d'un sort du joueur
     * @param tar indice de l'ennemi ciblé
    */
    void playTurn(Joueur& j, int sort, int tar);
    /**
     * @brief identique à playTurn

     * @param lignesSort le texte renvoyé à l'écran
    */
    void playTurnSDL(Joueur& j, int sort, int tar, vector<string>& lignesSort);
    /**
     * @brief vérifie l'état du combat
     * 
     * @param j le joueur du jeu en cours
     * @return int renvoie -1 si le combat continu, 0 si le joueur gagne 1, si il perd
     */
    int isFight(Joueur& j) const;
    /**
     * @brief affiche l'état des combattants 
     * 
     * @param j le joueur du jeu en cours
     */
    void affStat(Joueur& j) const;
    /**
     * @brief identique à affStat
     * @param lignes le texte renvoyé à l'écran 
     */
   void affStatSDL(Joueur& j, vector<string>& lignes);
    int groupSize();
    int getPVEnn_i(int i);
    int getPVmaxEnn_i(int i);



};


#endif
