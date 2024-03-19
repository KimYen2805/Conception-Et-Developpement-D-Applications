#include <iostream>
#include "affichage.h"
#include <SDL2/SDL_image.h>
using namespace std;

int main (int argc, char ** argv)
{
    Jeu Jeu("./data/Joueur");
		Joueur joueur = Jeu.getJoueur();
    // Initialisation de SDL
     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "Erreur d'initialisation de SDL: " << SDL_GetError() << endl;
        return 1;
    }
// Initialisation de SDL_image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        cerr << "Erreur d'initialisation de SDL_image: " << IMG_GetError() << endl;
        SDL_Quit();
        return 1;
    }
    ImageAffichage imageAffichage;

    //Affichage des deux images
    imageAffichage.Afficher(joueur);

    // Quit SDL_image
    IMG_Quit();

    // Quit SDL
    SDL_Quit();

    return 0;
}

