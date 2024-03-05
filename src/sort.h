#ifndef _SORT_H
#define _SORT_H
#include <string>
using namespace std;

class Sort
{

private:
    string nom;     //Nom du sort
    int coutMana;   //Le coup en mana du sort
    int puissance;  //Les dégâts infligés par le sort

public:
    Sort();

    void setNom() const;
    void setCoutMana() const;
    void setPuissance() const;

    string getNom() const;
    int getCoutMana() const;
    int getPuissance() const;
    }
#endif