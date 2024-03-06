#ifndef _ENNEMI_H
#define _ENNEMI_H
#include "sort.h"
#include <string>

class Ennemi {
    private:
        int point_de_vie;
        int puissance; 
        Sort *tab_Sort;
    public:
     // Constructeur
    Ennemi();

    // Destructeur
    ~Ennemi();
    // Getter pour pointDeVie
    int getPointDeVie() const;

    // Setter pour pointDeVie
    void setPointDeVie(int points);

    // Getter pour puissance
    int getPuissance() const;

    // Setter pour puissance
    void setPuissance(int power);

    // Fonction pour attaquer le joueur ?
    void attaquerJoueur();


};
#endif