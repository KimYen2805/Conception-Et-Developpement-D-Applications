#ifndef _JOUEUR_H
#define _JOUEUR_H
#include <string>
#include "sort.h"
#include "objet.h"
using namespace std;
const int NBSORT=50;

class Joueur{
    private :
    string nomJoueur;        // Nom du joueur
    int pointsDeVie;       // Points de vie du joueur actuelle
    int pointDeVieMax;
    int mana;
    int maxMana;
    Sort *tabSort;   // Tableau de sorts 
    public :
    //Contructeur
    Joueur();
    //Decontructeur
    ~Joueur();
    string getNomJoueur() const ;
    int getPoint_de_vie_Joueur() ;
    void setPoint_de_vie_Jouer(int pointsDeVie);
    int getMana();
    void setMana(int mana);

    
};
#endif




