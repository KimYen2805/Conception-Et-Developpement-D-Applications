#include <iostream>
#include "sort.h"
#include <string>
using namespace std;

Sort::Sort()
{ Effet effet;
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
void Sort::testRegression() {
    cout << "Exécution du test de régression pour la classe Sort..." << endl;

    // Test 1: Vérifiez si le nom du sort est "Agidyne"
    if (getNomSort() == "Agidyne") {
        cout << "Test 1 réussi : Le nom du sort est \"Agidyne\"." << endl;
    } else {
        cout << "Test 1 échoué : Le nom du sort n'est pas \"Agidyne\"." << endl;
    }

    // Test 2: Vérifiez si le coût en mana est égal à 7
    if (getCoutMana() == 7) {
        cout << "Test 2 réussi : Le coût en mana est égal à 7." << endl;
    } else {
        cout << "Test 2 échoué : Le coût en mana n'est pas égal à 7." << endl;
    }

    cout << "Test de régression terminé." << endl;
}