#include <iostream>
#include "sort.h"
#include <string>
using namespace std;

Sort::Sort()
{ 
    Effet effet;
    nomSort="Agidyne";
    cout=4;
    effetSort= effet;
}

    
void Sort::setNomSort(string nvNomSort) 
{
    nomSort=nvNomSort;
}

void Sort::setCout(int nvCout) 
{
    cout=nvCout;
}

void Sort::setEffetSort(Effet nvEffetSort)
{
    effetSort=nvEffetSort;
}

string Sort::getNomSort() const
{
    return nomSort;
}

int Sort::getCout() const
{
    return cout;
}

Effet Sort::getEffetSort() const
{
    return effetSort;
}