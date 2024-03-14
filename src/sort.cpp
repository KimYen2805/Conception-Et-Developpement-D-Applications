#include <iostream>
#include "sort.h"
#include <string>
using namespace std;

Sort::Sort()
{ 
    Effet effet;
    nomSort="Agidyne";
    coutS=4;
    effetSort= effet;
}

    
void Sort::setNomSort(string nvNomSort) 
{
    nomSort=nvNomSort;
}

void Sort::setCout(float nvCout) 
{
    coutS=nvCout;
}

void Sort::setEffetSort(Effet nvEffetSort)
{
    effetSort=nvEffetSort;
}

string Sort::getNomSort() const
{
    return nomSort;
}

float Sort::getCout() const
{
    return coutS;
}

Effet Sort::getEffetSort() const
{
    return effetSort;
}