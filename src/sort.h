#ifndef _SORT_H
#define _SORT_H
#include <string>
using namespace std;

class Sort
{

private:
    string nomSort;     //Nom du sort
    int coutMana;   //Le coup en mana du sort
    int puissance; //Les dégâts infligés par le sort

public:
    Sort();

    void setNomSort(string nvnomSort);
    void setCoutMana(int nvCout);
    void setPuissance(int nvPuissance);

    string getNomSort() const;
    int getCoutMana() const;
    int getPuissance() const;
};
#endif