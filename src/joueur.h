#ifndef _JOUEUR_H
#define _JOUEUR_H
#include <string>
#include "sort.h"
#include "objet.h"
using namespace std;

const int NBSORT=50;
const int NBOBJ=50;


class Joueur{
private :
   

    string nomJoueur;       // Nom du joueur

    int pointsDeVie;        // Points de vie du joueur actuelle
    int pointDeVieMax;

    int mana;
    int maxMana;

    Sort tabSort[NBSORT];          // Tableau de sorts 
    Objet tabObjet[NBOBJ];

public :
    //Contructeur
    Joueur();
    //Decontructeur
    ~Joueur();
    string getNomJoueur() const ;
    int getPVJoueur() ;
    void setPVJoueur(int pv);

    int getMana();
    void setMana(int mana);
//test 
    void testRegression();
    
};
#endif




