#ifndef _ENNEMI_H
#define _ENNEMI_H
#include "sort.h"
#include "objet.h"
#include <vector>
#include <iostream>
#include <string>

class Ennemi {
    private:
        int pointDeVie;
        int puissance; 
        vector<int> tabInd_Sort;

        
    public:
     // Constructeur
    Ennemi();

    // Destructeur
    ~Ennemi();
    // Getter pour pointDeVie
    int getPointDeVieEnnemi() const;

    // Setter pour pointDeVie
    void setPointDeVieEnnemi(int pv);


    void updatePVEnn(int pv);

    

    // Getter pour puissance
    int getPuissanceEnnemi() const;

    // Setter pour puissance
    void setPuissanceEnnemi(int power);

    void addSort(int sort);

    int nbEnne();
    int posXEnne(int n);
    int posYEnne(int n);
    // Fonction pour attaquer le joueur ?
    //void attaquerJoueur(); Plutôt une fonction qui sera dans combat

    //test 
    void testRegression();

};
#endif