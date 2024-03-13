#ifndef _JOUEUR_H
#define _JOUEUR_H
#include <string>
#include "sort.h"
#include "objet.h"
using namespace std;

const int NBSORT=3;
const int NBOBJ=50;


class Joueur{
private :
   

    string nomJoueur;       // Nom du joueur

    int pointDeVieMax;
    int pointsDeVie;        // Points de vie du joueur actuelle

    int maxMana;
    int mana;

    Sort tabSort[NBSORT];          // Tableau de sorts 
    Objet tabObjet[NBOBJ];

public :
    //Contructeur
    Joueur();
    Joueur(string nom, int pvMx, int mnMx, Sort inSort, Objet inObj);
    //Decontructeur
    ~Joueur();
    string getNomJoueur() const ;

    int getPVJoueur() ;
    void setPVJoueur(int pv);
    void updatePVJoueur(int pv);

    int getMana();
    void setMana(int ma);
    void updateMana(int ma);

    //test
    void testRegression();
    
};
#endif




