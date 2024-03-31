#include "affichage.h"
#include <iostream>
#include <assert.h>

using namespace std; 

/**
 * @brief Constructeur
 * renvoie une fenêtre SDL
*/
Affichage::Affichage() 
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
window=SDL_CreateWindow("ProjetCDKA",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,513,513,SDL_WINDOW_SHOWN);

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
	if(TTF_Init()==-1) 
	{
    cerr<<"TTF_Init : "<<TTF_GetError()<<endl;
    exit(2);
	}
	font = TTF_OpenFont("data/Arial.ttf", 17);
    if (font == nullptr) {
        cerr << "Échec du chargement de la police:  " << TTF_GetError() << endl;
        SDL_Quit();
        exit(3);
    }

	// Initialisation des couleurs 
    textColor = {255, 255, 255};
    rectColor = {241, 196, 15};
}

/**
 * @brief Destructeur
*/
Affichage::~Affichage()
{

  TTF_CloseFont(font); // Libère la police
    SDL_DestroyRenderer(renderer); // Libère le renderer
    SDL_DestroyWindow(window); // Libère la fenêtre
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}

void Affichage::dessinerPersonnage()
{ //pos joueur au début 
	int posXJoueur= 350; 
	int posYJoueur= 320;
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
}
void Affichage:: barres(Joueur joueur)
{
	string nomDeJoueur = joueur.getNomJoueur();
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

}
 void Affichage::CalculerDimensionsDuTexte(const vector<string>& li, int& larMax, int& hautTotale, vector<int>& haut)
 {
larMax = 0; //stocker la largeur max des textes
hautTotale = 0;
for (const auto& line : li) {
    SDL_Surface* tempSurface = TTF_RenderText_Blended(font, line.c_str(), textColor);
    larMax = max(larMax, tempSurface->w); //Mettre à jour la largeur max 
    hautTotale += tempSurface->h; //Ajouter la hauteur de cette ligne à la hauteur totale 
    haut.push_back(tempSurface->h); //Stoker la hauteur de cette ligne
    SDL_FreeSurface(tempSurface);
}
// Ajouter un espacement entre les lignes
int spacing = 5;
hautTotale += spacing * (li.size() - 1); //ajouter l'espacement total à la hauteur 
 }

 void Affichage::DessinerFondTexte(SDL_Renderer* renderer,int larMax, int hautTotale)
 {
	// dessiner le rectangle
SDL_Rect rect = {300, 0,larMax + 20, hautTotale + 20}; //Une marge autour du texte
SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, 255);
SDL_RenderFillRect(renderer, &rect);
 }


  void Affichage::AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes)
  {
int posY =10;
int spacing = 5;
for (size_t i = 0; i < lignes.size(); ++i) {
        SDL_Surface* textSurface = TTF_RenderText_Blended(font, lignes[i].c_str(), textColor);
        SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = {310, posY, textSurface->w, textSurface->h}; // Position avec marge
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        posY += textSurface->h + spacing;
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

    }
	//Réinitialiser la couleur du renderer pour ne pas affecter les dessins
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
void Affichage::AfficherInfo(Joueur joueur, Ennemi ennemi) {
    // Créer des lignes de texte sur le joueur et l'ennemi
    vector<string> lignes = {
        "Nom du joueur : " + joueur.getNomJoueur(),
        "Point de vie : " + to_string(joueur.getPVJoueur()),
        "Max mana : " + to_string(joueur.getMana() * 100 / joueur.getMAXMana()),
        "Point de vie ennemi : " + to_string(ennemi.getPointDeVieEnnemi())
    };

    // Appeler la fonction d'affichage du texte
   AfficherTexte(renderer, lignes);

}
//
void Affichage::AfficherFond()
{
    SDL_Surface *imageFond= IMG_Load("data/fond.jpg");
		if ( !imageFond)
		{
			cerr<< "Erreur de chargement de l'image: " << SDL_GetError() << endl;
		}
		SDL_Texture *textureImageFond = SDL_CreateTextureFromSurface(renderer, imageFond);
		SDL_FreeSurface(imageFond);
		
		//Positionnement et affichage d' imageBouton
		posFond.x = 0; 
		posFond.y= 0;
	SDL_QueryTexture(textureImageFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(renderer, textureImageFond,NULL, &posFond);
}
//
void Affichage::AfficherBoutonAction()
{
    SDL_Surface *imageBouton= IMG_Load("data/bouton.png");
		if ( !imageBouton)
		{
			cerr<< "Erreur de chargement de l'image: " << SDL_GetError() << endl;
		}
		SDL_Texture *textureImageBouton = SDL_CreateTextureFromSurface(renderer, imageBouton);
		SDL_FreeSurface(imageBouton);
		
		//Positionnement et affichage d' imageBouton
		posBouton.x = 230; 
		posBouton.y= 200;
	SDL_QueryTexture(textureImageBouton, NULL, NULL, &posBouton.w, &posBouton.h);
	SDL_RenderCopy(renderer, textureImageBouton,NULL, &posBouton);
}
void Affichage::HandleMouseClick(SDL_Event event)
{
	 // Vérifier l'événement de clic de la souris
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Vérifier si les coordonnées du clic de la souris se trouvent dans la position de l'image
        if (mouseX >= posBouton.x && mouseX <= posBouton.x + posBouton.w &&
            mouseY >= posBouton.y && mouseY <= posBouton.y + posBouton.h) {
            // le code de traitement lorsque le bouton est cliqué
            // Par exemple : ouvrir une nouvelle fenêtre 
            cout << "Le bouton a été cliqué !" << std::endl;
        }
    }
}

void Affichage::GererEvenements() {
    SDL_Event events;
	//
	//SDL_Rect boutonRect;
    //InitialiserRectBoutonAction(boutonRect);
    // Gestion evenements
    while (SDL_PollEvent(&events)) {
        if (events.type == SDL_QUIT) {
            SDL_Quit();
            exit(0); // Thoát khỏi chương trình hoàn toàn khi nhấn nút thoát
        } else if (events.type == SDL_KEYDOWN) {
            switch (events.key.keysym.scancode) {
                case SDL_SCANCODE_ESCAPE:
                    SDL_Quit();
                    exit(0);
                    break;
                default:
                    break;
            }
        }else if (events.type == SDL_MOUSEBUTTONDOWN) {
        if (events.button.button == SDL_BUTTON_LEFT) {
           // Gérer l'événement de clic de la souris ici
           HandleMouseClick(events);
            }
        }
    }
}

void Affichage::AfficherJeu(Joueur joueur, Ennemi ennemi,Jeu jeu) {
    bool quit = false;
    //Initialisez le rec pour le bouton 
    while (!quit) {
        GererEvenements();
        // Effacement de l'écran
        SDL_SetRenderDrawColor(renderer, 191, 201, 202, 255);
        SDL_RenderClear(renderer);
		//Font
		AfficherFond();
        dessinerPersonnage(); 
        barres(joueur); 
        AfficherInfo(joueur, ennemi);
		// Afficher le bouton "action"
        AfficherBoutonAction();
		
        // Affichage à l'écran
        SDL_RenderPresent(renderer);
        SDL_Delay(10); // Trì hoãn vòng lặp một chút để giảm tải CPU
    }
}
	//entrer le texte pour gerer le tableau de sort
				

			
			
