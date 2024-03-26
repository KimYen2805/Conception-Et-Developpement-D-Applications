#include <iostream>
#include "affichage.h"
using namespace std;

int main (int argc, char ** argv)
{

    Jeu Jeu;
	Joueur joueur = Jeu.getJoueur();
 
 
    ImageAffichage imageAffichage;

    //Affichage des deux images
    imageAffichage.Afficher(joueur);

    return 0;
}

