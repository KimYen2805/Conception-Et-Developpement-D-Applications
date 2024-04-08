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
// Création du renderer
renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

if (renderer == nullptr) 
{
    cerr << "Erreur de création de renderer SDL: " << SDL_GetError() << endl;
	SDL_DestroyWindow(window);
	SDL_Quit();
	exit(1);
}
// Initialisation des polices TTF
	if(TTF_Init()==-1) 
	{
    cerr<<"TTF_Init : "<<TTF_GetError()<<endl;
    exit(2);
	}
font = TTF_OpenFont("data/Arial.ttf", 17);
fontSaisie=TTF_OpenFont("data/Arial.ttf", 26);
    if (font == nullptr)
        {
        font ==TTF_OpenFont("data/Arial.ttf", 17);
        }
    if (font == nullptr) {
        cerr << "Échec du chargement de la police:  " << TTF_GetError() << endl;
        SDL_Quit();
        exit(3);
    }

	// Initialisation des couleurs 
    textColorInfo = {255, 255,0};
    rectColor = {0, 0, 0};
}

/**
 * @brief Destructeur
 * Libère toutes les ressources allouées par l'objet Affichage, y compris la fenêtre SDL, le renderer, les textures et les surfaces.
*/
Affichage::~Affichage()
{

    TTF_CloseFont(font); 
     TTF_CloseFont(fontSaisie); 
    // Libère la police

    SDL_DestroyRenderer(renderer); // Libère le renderer
    SDL_DestroyWindow(window); // Libère la fenêtre
     // Libération des textures et surfaces
    SDL_DestroyTexture(textureImage1);
    SDL_FreeSurface(image1);

    SDL_DestroyTexture(textureImage2);
    SDL_FreeSurface(image2);

    SDL_DestroyTexture(textureImageFond);
    SDL_FreeSurface(imageFond);

   SDL_FreeSurface( tempSurface);

   SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);//

     SDL_DestroyTexture(textureImageBouton);
    SDL_FreeSurface(imageBouton);
    
    SDL_DestroyTexture(textInputTexture);
    SDL_FreeSurface(textInputSurface);
 // Libération de SDL_ttf et SDL_image
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}
/**
 * @brief Dessine les personnages (joueur et ennemi) sur l'écran.
*/
void Affichage::dessinerPersonnage()
{ // Position initiale des personnages
	int posXJoueur= 350; 
	int posYJoueur= 320;
	// Affichage de l'image ennemi
        image1= IMG_Load("data/ennemi.png");
      if (!image1)
      {
         cerr << "Erreur de chargement de l'image: " << SDL_GetError() << endl;
        }
        textureImage1= SDL_CreateTextureFromSurface(renderer, image1);
		//Positionnement et affichage d'image ennemi
		SDL_Rect posIma1;
		posIma1.x = 100; 
		posIma1.y= 100;
		SDL_QueryTexture(textureImage1, NULL, NULL, &posIma1.w, &posIma1.h);
		SDL_RenderCopy(renderer, textureImage1,NULL, &posIma1);
		//affichage de l'image joueur 
		image2= IMG_Load("data/joueur.png");
		if ( !image2)
		{
			cerr<< "Erreur de chargement de l'image: " << SDL_GetError() << endl;
		}
		textureImage2 = SDL_CreateTextureFromSurface(renderer, image2);
		
		//Positionnement et affichage d'image 2 joueur
	SDL_Rect posIma2;
		posIma2.x = posXJoueur; 
		posIma2.y= posYJoueur;
	SDL_QueryTexture(textureImage2, NULL, NULL, &posIma2.w, &posIma2.h);
	SDL_RenderCopy(renderer, textureImage2,NULL, &posIma2);

}
/**
 * @brief Affiche les barres de santé et de mana du joueur.
 * @param joueur Objet représentant le joueur.
*/
void Affichage:: barres(Joueur joueur)
{
    // Récupération des données du joueur
	string nomDeJoueur = joueur.getNomJoueur();
	int pointDeVieJoueur = joueur.getPVJoueur(); // Point de vie du joueur
    int maxManaJoueur = joueur.getMana()*100/joueur.getMAXMana();    // Mana maximale du joueur
	Ennemi ennemi;
    int pointDeVieEnnemi= ennemi.getPointDeVieEnnemi(); 
// Affichage de la barre de vie du joueur
	SDL_Rect rePo; 
		rePo.x =350; 
		rePo.y =400;
		rePo.w = pointDeVieJoueur;
		rePo.h =10;
	SDL_SetRenderDrawColor(renderer,255,0,0,0);
	SDL_RenderFillRect(renderer, &rePo);
		// Affichage de la barre de mana du joueur
		SDL_Rect reMa; 
		reMa.x =350; 
		reMa.y =420;
		reMa.w = maxManaJoueur;
		reMa.h =10;
	SDL_SetRenderDrawColor(renderer,0,0,255,0);
	SDL_RenderFillRect(renderer, &reMa);

}
/**
 * @brief Calcule les dimensions du texte à afficher.
 * @param li Vecteur contenant les lignes de texte.
 * @param larMax Référence à la largeur maximale du texte.
 * @param hautTotale Référence à la hauteur totale du texte.
 * @param haut Vecteur contenant les hauteurs de chaque ligne de texte.
*/
 void Affichage::CalculerDimensionsDuTexte(const vector<string>& li, int& larMax, int& hautTotale, vector<int>& haut)
 {
larMax = 0; //stocker la largeur max des textes
hautTotale = 0;
for (const auto& line : li) {
     tempSurface = TTF_RenderText_Blended(font, line.c_str(), textColorInfo);
    larMax = max(larMax, tempSurface->w); //Mettre à jour la largeur max 
    hautTotale += tempSurface->h; //Ajouter la hauteur de cette ligne à la hauteur totale 
    haut.push_back(tempSurface->h); //Stoker la hauteur de cette ligne
}
// Ajouter un espacement entre les lignes
int spacing = 5;
hautTotale += spacing * (li.size() - 1); //ajouter l'espacement total à la hauteur 
 }
/**
 * @brief Dessine un rectangle de fond pour afficher le texte.
 * @param renderer Pointeur vers le renderer SDL.
 * @param larMax Largeur maximale du texte.
 * @param hautTotale Hauteur totale du texte.
*/
 void Affichage::DessinerFondTexte(SDL_Renderer* renderer,int larMax, int hautTotale)
 {
	 // Dessine un rectangle en arrière-plan pour le texte
SDL_Rect rect = {300, 0,larMax + 20, hautTotale + 20}; //Une marge autour du texte
SDL_SetRenderDrawColor(renderer, rectColor.r, rectColor.g, rectColor.b, 255);
SDL_RenderFillRect(renderer, &rect);
 }

/**
 * @brief Affiche le texte sur l'écran.
 * @param renderer Pointeur vers le renderer SDL.
 * @param lignes Vecteur contenant les lignes de texte à afficher.
*/
  void Affichage::AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes)
  {
int posY =10;
int spacing = 5;
for (size_t i = 0; i < lignes.size(); ++i) {
         textSurface = TTF_RenderText_Blended(font, lignes[i].c_str(), textColorInfo);
         textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_Rect textRect = {310, posY, textSurface->w, textSurface->h}; // Position avec marge
        SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
        posY += textSurface->h + spacing;

    }
	//Réinitialiser la couleur du renderer pour ne pas affecter les dessins
SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
/**
 * @brief Affiche les informations du joueur et de l'ennemi.
 * @param joueur Objet représentant le joueur.
 * @param ennemi Objet représentant l'ennemi.
*/
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
/*void Affichage::AfficherFond()
{
    imageFond= IMG_Load("data/fond.jpg");
		if ( !imageFond)
		{
			cerr<< "Erreur de chargement de l'image: " << SDL_GetError() << endl;
		}
		textureImageFond = SDL_CreateTextureFromSurface(renderer, imageFond);
		
		//Positionnement et affichage d' imageBouton
		posFond.x = 0; 
		posFond.y= 0;
	SDL_QueryTexture(textureImageFond, NULL, NULL, &posFond.w, &posFond.h);
	SDL_RenderCopy(renderer, textureImageFond,NULL, &posFond);
}
*/


/*void Affichage::HandleMouseClick(SDL_Event event)
{
	 // Vérifier l'événement de clic de la souris
    if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Vérifier si les coordonnées du clic de la souris se trouvent dans la position de l'image
        if (mouseX >= posBouton.x && mouseX <= posBouton.x + posBouton.w &&
            mouseY >= posBouton.y && mouseY <= posBouton.y + posBouton.h) {
            // le code de traitement lorsque le bouton est cliqué
            boutonClique = true;
            cout << "Le bouton a été cliqué , activant la saisie de texte!" << std::endl;
    
        }
    }
}
void Affichage::AfficherBoutonAction()
{
   if (!boutonClique) {
        imageBouton = IMG_Load("data/bouton.png");
        if (!imageBouton) {
            cerr << "Erreur de chargement de l'image: " << SDL_GetError() << endl;
        }
        textureImageBouton = SDL_CreateTextureFromSurface(renderer, imageBouton);
        //Positionnement et affichage d' imageBouton
        posBouton.x = 230;
        posBouton.y = 200;
        SDL_QueryTexture(textureImageBouton, NULL, NULL, &posBouton.w, &posBouton.h);
        SDL_RenderCopy(renderer, textureImageBouton, NULL, &posBouton);
    }
}*/
/**
 * @brief Gère les événements SDL, tels que les saisies clavier et la fermeture de la fenêtre.
*/
void Affichage::GererEvenements() {
    SDL_Event events;
    SDL_StartTextInput();

    while (SDL_PollEvent(&events)) {
        if (events.type == SDL_QUIT) {
            SDL_Quit();
            exit(0); 
        } else if (events.type == SDL_KEYDOWN) {
            if (events.key.keysym.sym == SDLK_ESCAPE) {
                SDL_Quit();
                exit(0);
            } 
            else if (textInputActive) {
                if (events.key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0) {
                    inputText.pop_back();
                    renderText = true;
                } else if (events.key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL) {
                    SDL_SetClipboardText(inputText.c_str());
                } else if (events.key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL) {
                    inputText = SDL_GetClipboardText();
                    renderText = true;
                }
            }
        } else if (events.type == SDL_TEXTINPUT) {
            if (!(SDL_GetModState() & KMOD_CTRL && (events.text.text[0] == 'c' || events.text.text[0] == 'C' || events.text.text[0] == 'v' || events.text.text[0] == 'V'))) {
                inputText += events.text.text;
                renderText = true;
            }
        } /*else if (events.type == SDL_MOUSEBUTTONDOWN && events.button.button == SDL_BUTTON_LEFT) {
            HandleMouseClick(events);
        } */
        else if (events.key.keysym.sym == SDLK_RETURN) { 
                inputText = ""; 
                renderText= true;
    }
    }
   
    SDL_StopTextInput();
}
/**
 * @brief Affiche le texte saisi par l'utilisateur.
*/
void Affichage::AfficherTexteSaisie() {
    if (renderText){
        SDL_RenderClear(renderer);
         SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
             SDL_RenderFillRect(renderer, NULL);
    if (!inputText.empty()) {
        textInputSurface = TTF_RenderText_Blended(fontSaisie, inputText.c_str(), {255, 255,0});
        if (textInputSurface == NULL) {
            std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
        } else {
            textInputTexture = SDL_CreateTextureFromSurface(renderer, textInputSurface);
            SDL_Rect textRect = {10, 450,textInputSurface->w, textInputSurface->h};

            SDL_RenderCopy(renderer, textInputTexture, NULL, &textRect);
        }
    }
        
    }
    SDL_RenderPresent(renderer);
    renderText = false;
}

/**
 * @brief Affiche le jeu en cours.
*/
void Affichage::AfficherJeu(Joueur joueur, Ennemi ennemi, Jeu jeu) {
    bool quitter = false;
    while (!quitter) {
        GererEvenements();
    AfficherTexteSaisie();
        // Affichage des éléments du jeu
      // AfficherFond();
        dessinerPersonnage(); 
        barres(joueur); 
        AfficherInfo(joueur, ennemi);
      /* AfficherBoutonAction();*/
        
        
        // Affichage à l'écran
       SDL_RenderPresent(renderer);

        // Vérification si l'utilisateur veut quitter
        SDL_Delay(10); 
    }
    
}

				
			
			
