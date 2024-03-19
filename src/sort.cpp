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

void Sort::affSort(){
    if (effetSort.getNomEffet()=="degatMana")
    {    
        cout<<nomSort<<" coute "<<coutS<<" mana pour infliger "<<effetSort.getPuissanceEffet()<<" degat."<<endl;
    }else
    if (effetSort.getNomEffet()=="degatVie")
    {    
        cout<<nomSort<<" coute "<<coutS<<" de la vie actuelle pour infliger "<<effetSort.getPuissanceEffet()<<" de la vie actuelle en degat."<<endl;
    }else
    if (effetSort.getNomEffet()=="soinVie")
    {    
        cout<<nomSort<<" coute "<<coutS<<" mana pour soigner "<<effetSort.getPuissanceEffet()<<" vie."<<endl;
    /*}else
    if (effetSort.getNomEffet()=="SoinMana")
    {    
      cout<<nomSort<<" coute "<<coutS<<" mana pour infliger"<<effetSort.getPuissanceEffet()<<" degat."<<endl; */ 
    }else{
        cout<<"woops"<<endl;
    }
}