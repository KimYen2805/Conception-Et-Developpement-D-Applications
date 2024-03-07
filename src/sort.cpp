#include <iostream>
#include "sort.h"
#include <string>
using namespace std;

Sort::Sort()
{
    nomSort='Agidyne';
    coutMana=7;
    puissance=16;

}


    
void Sort::setNomSort(string nvNomSort) 
{
    nomSort=nvNomSort;
}

void Sort::setCoutMana(int nvCout) 
{
    coutMana=nvCout;
}

void Sort::setPuissance(int nvPuissance)
{
    puissance=nvPuissance;
}

string Sort::getNomSort() const
{
    return nomSort;
}

int Sort::getCoutMana() const
{
    return coutMana;
}

int Sort::getPuissance() const
{
    return puissance;
}