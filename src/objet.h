#ifndef _OBJET_H
#define _OBJET_H

#include "effet.h"
#include <string>
using namespace std;
class Objet
{

private:
    string nomObjet;    //Nom de l'objet
    int quantite;       //Le coup en mana du sort
    Effet effetObjet;      //Les dégâts infligés par le sort

public:
    Objet();
    /**
     * @brief change le nom de l'objet 
     * @param nom
    */
    void setNomObjet(string nom);
    /**
     * @brief change la quantité d'objet 
     * @param nvQut
    */
    void setQuantite(int nvQut);
    /**
     * @brief change l'effet de l'objet 
     * @param nvEffet
    */
    void setEffetObjet(Effet nvEffet);
    
   // Objet &operator=(const Objet &other);
};

#endif

