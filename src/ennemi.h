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
        int pvMax;
        int puissance; 
        vector<int> tabInd_Sort;

        
    public:
     // Constructeur
    Ennemi();

    // Destructeur
    ~Ennemi();
   
    /**
     * @brief renvoi pointDeVie
     * 
     * @return int 
     */
    int getPointDeVieEnnemi() const;
    /**
     * @brief renvoi pvMax
     * 
     * @return int 
     */
    int getPVmaxEnnemi() const;

    /**
     * @brief Set pointDeVie 
     * 
     * @param pv 
     */
    void setPointDeVieEnnemi(int pv);
    /**
     * @brief set pvMax et pointDevie
     * 
     * @param pv 
     */
    void setPVmaxEnnemi(int pv);
    /**
     * @brief ajoute pv à pointDeVie sans dépasser pvMax ou en dessous de 0
     * 
     * @param pv 
     */
    void updatePVEnn(float pv);

    // Getter pour puissance
    int getPuissanceEnnemi() const;

    // Setter pour puissance
    void setPuissanceEnnemi(int power);

    void addSort(int sort);
    int getSort(int n);
    int getSsize();

    int nbEnne();
    int posXEnne(int n);
    int posYEnne(int n);
    // Fonction pour attaquer le joueur ?
    //void attaquerJoueur(); Plutôt une fonction qui sera dans combat

    //test 
    void testRegression();

};
#endif