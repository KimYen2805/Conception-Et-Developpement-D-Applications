#include "affichage.h"
#include <iostream>
#include <assert.h>
#include <SDL2/SDL_image.h>
/**
 * @brief Constructeur
 * renvoie une fenêtre SDL
*/
ImageAffichage::ImageAffichage()
{
window=SDL_CreateWindow("Jeu",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_SHOWN);

if (window == nullptr) 
{
    cerr << "Erreur de création de fenêtre SDL"<<endl;
}
renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

if (renderer == nullptr) 
{
    cerr << "Erreur de création de renderer SDL: " << SDL_GetError() << endl;
}
}

/**
 * @brief Destructeur
*/
ImageAffichage::~ImageAffichage()
{

 SDL_DestroyRenderer(renderer); // Libère la mémoire associée au renderer
 SDL_DestroyWindow(window); // Libère la mémoire associée à la fenêtre
}

/**
 * @brief Affiche l'image dans la fenêtre
 * @param im : l'image
*/
void ImageAffichage::Afficher() {
	// initialisation boucle
	SDL_Event events;
	bool quit = false;
	unsigned int zoom = 1;
	// boucle
	while (!quit) {
		// recuperation taille fenetre
		int dimxFenetre, dimyFenetre;
		SDL_GetWindowSize(window, &dimxFenetre, &dimyFenetre);
		// gestion evenements
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) quit = true;
			else if (events.type == SDL_KEYDOWN) {
				switch (events.key.keysym.scancode) {
				case SDL_SCANCODE_T:
					zoom++;
					break;
				case SDL_SCANCODE_G:
					if (zoom > 1) zoom--;
					break;
				case SDL_SCANCODE_ESCAPE:
					quit = true;
					break;
				default:
					break;
				}
			}
		}
		// affichage image
        SDL_Surface *image= IMG_Load("data/annemi.png");
      if (!image)
      {
         cerr << "Erreur de chargement de l'image: " << SDL_GetError() << endl;
        }
        SDL_Texture *textureImage= SDL_CreateTextureFromSurface(renderer, image);
        SDL_FreeSurface(image);

      }
}
   // SDL_RenderPresent(renderer){}


