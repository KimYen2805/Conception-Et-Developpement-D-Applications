#include <iostream>
#include "sort.h"
#include <string>
using namespace std;

Sort::Sort()
{ 
    Effet effet;
    nomSort="Agidyne";
    coutMana=7;
    effetSort= effet;
}

    
void Sort::setNomSort(string nvNomSort) 
{
    nomSort=nvNomSort;
}

void Sort::setCoutMana(int nvCout) 
{
    coutMana=nvCout;
}

void Sort::setEffetSort(Effet nvEffetSort)
{
    effetSort=nvEffetSort;
}

string Sort::getNomSort() const
{
    return nomSort;
}

int Sort::getCoutMana() const
{
    return coutMana;
}

Effet Sort::getEffetSort() const
{
    return effetSort;
}