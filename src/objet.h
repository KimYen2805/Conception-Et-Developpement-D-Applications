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

    void setNomObjet(string nom);
    void setQuantite(int nvCout);
    void setEffetObjet(int nvPuissance);

    string getNom() const;
    int getCoutMana() const;
    int getPuissance() const;
};

#endif