#ifndef _SORT_H
#define _SORT_H
#include "effet.h"
#include <string>
using namespace std;

class Sort
{

private:
    string nomSort;
    int cout;
    Effet effetSort;

public:
    Sort();

    void setNomSort(string nvnomSort);
    void setCout(int nvCout);
    void setEffetSort(Effet nvEffetSort);

    string getNomSort() const;
    int getCout() const;
    Effet getEffetSort() const;
};
#endif