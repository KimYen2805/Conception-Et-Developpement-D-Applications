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
void Sort::affSortSDL(std::stringstream& ss) {
    std::string tempStr; // Variable temporaire pour stocker les lignes
    if (effetSort.getNomEffet() == "degatMana") {    
        tempStr = nomSort + " coute " + std::to_string(coutS) + " points de mana pour infliger " + std::to_string(effetSort.getPuissanceEffet()) + " degats.";
    } else if (effetSort.getNomEffet() == "degatVie") {    
        tempStr = nomSort + " coute " + std::to_string(coutS) + " points de vie actuelle pour infliger " + std::to_string(effetSort.getPuissanceEffet()) + " points de vie actuelle en degats.";
    } else if (effetSort.getNomEffet() == "soinVie") {    
        tempStr = nomSort + " coute " + std::to_string(coutS) + " points de mana pour soigner " + std::to_string(effetSort.getPuissanceEffet()) + " points de vie.";
    } else {
        tempStr = "Oops";
    }

    // Diviser la chaîne en lignes plus courtes et les ajouter au stringstream
    for (size_t i = 0; i < tempStr.length(); i += 52) { // 50 est la longueur maximale de chaque ligne
        ss << tempStr.substr(i, 52) << std::endl;
    }
}

