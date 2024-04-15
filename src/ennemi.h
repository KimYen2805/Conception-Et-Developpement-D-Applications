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

    /**
     * @brief set puissance avec power
     * @param power 
    */
    void setPuissanceEnnemi(int power);

    /**
     * @brief ajoute un indice de sort au vecteur sort
     * @return int
    */
    void addSort(int sort);
    /**
     * @brief l'indice du sort en position n
     * @return int
    */
    int getSort(int n);
    /**
     * @brief revoie la taille du vecteur sort
    */
    int getSsize();
    /**
     * @brief revoie la taille du vecteur ennGroup
    */
    int nbEnne();
    /**
     * @brief revoie la position x sur l'écran en fonction du nombre d'ennemi
     * @return int
    */
    int posXEnne(int n);
    /**
     * @brief revoie la position y sur l'écran en fonction du nombre d'ennemi
     * @return int
    */
    int posYEnne(int n);
    //void attaquerJoueur(); Plutôt une fonction qui sera dans combat

    //test 
    void testRegression();

};
#endif