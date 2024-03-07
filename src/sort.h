#ifndef _SORT_H
#define _SORT_H
#include "effet.h"
#include <string>
using namespace std;

class Sort
{

private:
    string nomSort;     //Nom du sort
    int coutMana;   //Le coup en mana du sort
    Effet effetSort; //Les effets causé par le sort

public:
    Sort();

    void setNomSort(string nvnomSort);
    void setCoutMana(int nvCout);
    void setEffetSort(Effet nvEffetSort);

    string getNomSort() const;
    int getCoutMana() const;
    Effet getEffetSort() const;
};
#endif