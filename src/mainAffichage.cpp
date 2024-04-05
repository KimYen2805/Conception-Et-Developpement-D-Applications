#include <iostream>
#include "affichage.h"
using namespace std;

int main (int argc, char ** argv)
{

   Jeu Jeu;
    Ennemi ennemi;
	Joueur joueur = Jeu.getJoueur();
 
 
    Affichage affichage;

    //Affichage des deux images
    affichage.AfficherJeu( joueur,ennemi, Jeu); 

    return 0;
}

