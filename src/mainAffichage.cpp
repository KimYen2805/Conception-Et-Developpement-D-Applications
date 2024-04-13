#include <iostream>
#include "affichage.h"
using namespace std;

int main (int argc, char ** argv)
{

   Jeu jeu;
    Ennemi ennemi;
	Joueur joueur = jeu.getJoueur();
    Dialogue di;
 
    Affichage affichage;

    //Affichage des deux images
    affichage.AfficherJeu( joueur,ennemi, jeu, &di); 
     

    return 0;
}

