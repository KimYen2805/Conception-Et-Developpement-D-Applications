#include "affichage.h"
#include <iostream>
#include <assert.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
using namespace std; 

/**
 * @brief Constructeur
 * renvoie une fenêtre SDL
*/
ImageAffichage::ImageAffichage()
{
	// Initialisation de SDL
     if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cerr << "Erreur d'initialisation de SDL: " << SDL_GetError() << endl;
        exit(1);
    }
// Initialisation de SDL_image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG) {
        cerr << "Erreur d'initialisation de SDL_image: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1) ;
    }
	//Créaction de la fenetre SDL
window=SDL_CreateWindow("ProjetCDKA",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,500,500,SDL_WINDOW_SHOWN);

if (window == nullptr) 
{
    cerr << "Erreur de création de fenêtre SDL"<<endl;
	SDL_Quit();
	exit (1);
}
renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

if (renderer == nullptr) 
{
    cerr << "Erreur de création de renderer SDL: " << SDL_GetError() << endl;
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(1);
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
void ImageAffichage::Afficher(Joueur joueur) {
	// initialisation boucle
	SDL_Event events;
	bool quit = false;
	//pos joueur au début 
	int posXJoueur= 350; 
	int posYJoueur= 320;
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
			else if (events.type== SDL_KEYDOWN )
			{
				switch (events.key.keysym.scancode)
				{
					case SDL_SCANCODE_ESCAPE:
						quit= true;
						break; 
					case SDL_SCANCODE_UP:
						posYJoueur -= 10;
						break;
					case SDL_SCANCODE_DOWN: 
						posYJoueur += 10;
						break;
					case SDL_SCANCODE_LEFT: 
						posXJoueur -= 10;
						break;
					case SDL_SCANCODE_RIGHT: 
						posXJoueur += 10;
						break;
					default:
						break;
				}
				
			}
			}
	//Effacement de l'écran
	SDL_SetRenderDrawColor( renderer, 191, 201,202,255);
	SDL_RenderClear(renderer);

		// Affichage de l'image ennemi
        SDL_Surface *image1= IMG_Load("data/ennemi.png");
      if (!image1)
      {
         cerr << "Erreur de chargement de l'image: " << SDL_GetError() << endl;
        }
        SDL_Texture *textureImage1= SDL_CreateTextureFromSurface(renderer, image1);
        SDL_FreeSurface(image1);
		//Positionnement et affichage d'image ennemi
		SDL_Rect posIma1;
		posIma1.x = 100; 
		posIma1.y= 100;
		SDL_QueryTexture(textureImage1, NULL, NULL, &posIma1.w, &posIma1.h);
		SDL_RenderCopy(renderer, textureImage1,NULL, &posIma1);


		//affichage de l'image joueur 
		SDL_Surface *image2= IMG_Load("data/joueur.png");
		if ( !image2)
		{
			cerr<< "Erreur de chargement de l'image: " << SDL_GetError() << endl;
		}
		SDL_Texture *textureImage2 = SDL_CreateTextureFromSurface(renderer, image2);
		SDL_FreeSurface(image2);
		
		//Positionnement et affichage d'image 2 joueur
	SDL_Rect posIma2;
		posIma2.x = posXJoueur; 
		posIma2.y= posYJoueur;
	SDL_QueryTexture(textureImage2, NULL, NULL, &posIma2.w, &posIma2.h);
	SDL_RenderCopy(renderer, textureImage2,NULL, &posIma2);
	// point de vie joueur, mana, point de vie de l'ennemi
	int pointDeVieJoueur = joueur.getPVJoueur(); // Point de vie du joueur
    int maxManaJoueur = joueur.getMana()*100/joueur.getMAXMana();    // Mana maximale du joueur
	   Ennemi ennemi;
    int pointDeVieEnnemi= ennemi.getPointDeVieEnnemi(); 
		// une barre (pointDVactu)
	SDL_Rect rePo; 
		rePo.x =350; 
		rePo.y =400;
		rePo.w = pointDeVieJoueur;
		rePo.h =10;
	SDL_SetRenderDrawColor(renderer,255,0,0,0);
	SDL_RenderFillRect(renderer, &rePo);
		//une barre (mana)
		SDL_Rect reMa; 
		reMa.x =350; 
		reMa.y =420;
		reMa.w = maxManaJoueur;
		reMa.h =10;
	SDL_SetRenderDrawColor(renderer,0,0,255,0);
	SDL_RenderFillRect(renderer, &reMa);
	//Affichage des res en rectangle text
	if(TTF_Init()==-1) 
	{
    cerr<<"TTF_Init : "<<TTF_GetError()<<endl;
    exit(2);
	}
	
	TTF_Font *font= TTF_OpenFont("data/Arial.ttf",17);
	if ( font== nullptr)
	{
		cerr<<"Échec du chargement de la police:  "<<TTF_GetError()<<endl;
		exit(3);
	}
//Définir la couleur du texte
SDL_Color textColor = {33, 50, 61}; 
SDL_Color rectColor = {241, 196, 15}; 

vector<std::string> lines = {
    "Nom du joueur:",
    "Point de vie: " + std::to_string(pointDeVieJoueur),
    "Max mana: " + std::to_string(maxManaJoueur),
    "Point de vie ennemi: " + std::to_string(pointDeVieEnnemi)
};

int maxWidth = 0; //stocker la largeur max des textes
int totalHeight = 0; //caculer la hauteur totale 
vector<int> heights; //stocker la hauteur de chaque ligne de texte

// Caculer la largeur max et la hauteur totale
for (const auto& line : lines) {
    SDL_Surface* tempSurface = TTF_RenderText_Blended(font, line.c_str(), textColor);
    maxWidth = max(maxWidth, tempSurface->w); //Mettre à jour la largeur max 
    totalHeight += tempSurface->h; //Ajouter la hauteur de cette ligne à la hauteur totale 
    heights.push_back(tempSurface->h); //Stoker la hauteur de cette ligne
    SDL_FreeSurface(tempSurface);
}

// Ajouter un espacement entre les lignes
int spacing = 5;
totalHeight += spacing * (lines.size() - 1); //ajouter l'espacement total à la hauteur 

// dessiner le rectangle
SDL_Rect rect = {300, 0, maxWidth + 20, totalHeight + 20}; //Une marge autour du texte
SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, 255);
SDL_RenderFillRect(renderer, &rect);

int posY = rect.y + 10; // Pos le premier texte avec un marge
// Dessiner chaque ligne de texte à l'intérieur du rectangle
for (const auto& line : lines) {
    SDL_Surface* textSurface = TTF_RenderText_Blended(font, line.c_str(), textColor);
    SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textRect = {rect.x + 10, posY, textSurface->w, textSurface->h}; // Aligner le texte avec une marge
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);

    posY += textSurface->h + spacing; //Mettre à jour la pos pour la ligne suivante

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

//Réinitialiser la couleur du renderer pour ne pas affecter les dessins
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//Libérer la police et quitter TTF
TTF_CloseFont(font);
TTF_Quit();
	//Affichage à l'écran
	SDL_RenderPresent(renderer);
      }
}


