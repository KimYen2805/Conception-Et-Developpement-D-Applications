#ifndef _OBJET_H
#define _OBJET_H

#include <string>
using namespace std;

class Objet
{

private:
    string nomObjet;    //Nom du sort
    int coutMana;       //Le coup en mana du sort
    int puissance;      //Les dégâts infligés par le sort

public:
    Objet();

    void setNom(string nom);
    void setCoutMana(int nvCout);
    void setPuissance(int nvPuissance);

    string getNom() const;
    int getCoutMana() const;
    int getPuissance() const;
};

#endif