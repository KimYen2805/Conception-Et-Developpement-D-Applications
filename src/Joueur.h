#ifndef _JOUEUR_H
#define _JOUEUR_H
#include <string>
#include "sort.h"
using namespace std;
class Joueur{
    private :

    string nom;        // Nom du joueur
    int pointsDeVie;        // Points de vie du joueur actuelle
    int pointDeVieMax;
    int mana;
    int maxMana;
    Sort* tabSort;   // Tableau de sorts 


    public :
    //contructeur
    Joueur();
    //decontructeur
    ~Joueur();
    string getNom() const ;
    int getPoint_de_vie() ;
    void setPoint_de_vie(int pointsDeVie);
    
};





