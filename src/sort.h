#ifndef _SORT_H
#define _SORT_H
#include "effet.h"
#include <string>
using namespace std;

class Sort
{

private:
    string nomSort;
    int coutMana;
    Effet effetSort;

public:
    Sort();

    void setNomSort(string nvnomSort);
    void setCoutMana(int nvCout);
    void setEffetSort(Effet nvEffetSort);

    string getNomSort() const;
    int getCoutMana() const;
    Effet getEffetSort() const;
    void testRegression();
};
#endif