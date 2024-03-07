#include <iostream>
#include "sort.h"
#include <string>
using namespace std;

Sort::Sort()
{
    nom='Agidyne';
    coutMana=7;
    puissance=16;

}


    
void Sort::setNom(string nvNom) 
{
    nom=nvNom;
}

void Sort::setCoutMana(int nvCout) 
{
    coutMana=nvCout;
}

void Sort::setPuissance(int nvPuissance)
{
    puissance=nvPuissance;
}

string Sort::getNom() const
{
    return nom;
}

int Sort::getCoutMana() const
{
    return coutMana;
}

int Sort::getPuissance() const
{
    return puissance;
}