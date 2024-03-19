#include "jeu.h"
#include <iostream>
using namespace std;

int main()
{
    Jeu Jeu("./data/Joueur", "./data/Graphe");
    //Combat combat;
    Jeu.getJoueur().testRegression();
    
    //combat.castSort();
    

    return 0;
}





