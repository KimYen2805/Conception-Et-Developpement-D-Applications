#ifndef _SORT_H
#define _SORT_H
#include "effet.h"
#include <string>
using namespace std;

class Sort
{

private:
    string nomSort;
    float coutS;
    Effet effetSort;

public:
    Sort();

    void setNomSort(string nvnomSort);
    void setCout(float nvCout);
    void setEffetSort(Effet nvEffetSort);

    string getNomSort() const;
    float getCout() const;
    Effet getEffetSort() const;

    void affSort();
};
#endif