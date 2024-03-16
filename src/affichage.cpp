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
window=SDL_CreateWindow("ProjetCDKA",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_SHOWN);

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
void ImageAffichage::Afficher() {
	// initialisation boucle
	SDL_Event events;
	bool quit = false;
	// boucle
	while (!quit && !SDL_QuitRequested()) {
		// recuperation taille fenetre
		int dimxFenetre, dimyFenetre;
		SDL_GetWindowSize(window, &dimxFenetre, &dimyFenetre);
		// gestion evenements
		while (SDL_PollEvent(&events)) {
			if (events.type == SDL_QUIT) 
			{ 
				quit = true;
			}
			else if (events.type== SDL_KEYDOWN && events.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			{
				quit= true;
			}
			}
	
		// Affichage de l'image ennemi
        SDL_Surface *image1= IMG_Load("data/ennemi.png");
      if (!image1)
      {
         cerr << "Erreur de chargement de l'image: " << SDL_GetError() << endl;
        }
        SDL_Texture *textureImage1= SDL_CreateTextureFromSurface(renderer, image1);
        SDL_FreeSurface(image1);
		//affichage de l'image joueur 
		SDL_Surface *image2= IMG_Load("data/joueur.png");
		if ( !image2)
		{
			cerr<< "Erreur de chargement de l'image: " << SDL_GetError() << endl;
		}
		SDL_Texture *textureImage2 = SDL_CreateTextureFromSurface(renderer, image2);
		SDL_FreeSurface(image2);
		//Positionnement et affichage d'image 1
		SDL_Rect posIma1;
		posIma1.x = 100; 
		posIma1.y= 100;
		SDL_QueryTexture(textureImage1, NULL, NULL, &posIma1.w, &posIma1.h);
		SDL_RenderCopy(renderer, textureImage1,NULL, &posIma1);
		//Positionnement et affichage d'image 2
		SDL_Rect posIma2;
		posIma2.x = 300; 
		posIma2.y= 300;
		SDL_QueryTexture(textureImage2, NULL, NULL, &posIma2.w, &posIma2.h);
		SDL_RenderCopy(renderer, textureImage2,NULL, &posIma2);
		//Affichage à l'écran
		SDL_RenderPresent(renderer);
      }
}
  


