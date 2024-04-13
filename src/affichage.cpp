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
renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE);

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
//chargé toutes les image
//image fond
// Load image and create texture
textureImageFond = IMG_LoadTexture(renderer, "data/fond.jpg");
if (!textureImageFond) {
    cerr << "Erreur de chargement de l'image: " << SDL_GetError() << endl;
}

// Load enemy image and create texture
textureImage1 = IMG_LoadTexture(renderer, "data/ennemi.png");
if (!textureImage1) {
    cerr << "Erreur de chargement de l'image de l'ennemi: " << SDL_GetError() << endl;
}

// Load player image and create texture
textureImage2 = IMG_LoadTexture(renderer, "data/joueur.png");
if (!textureImage2) {
    cerr << "Erreur de chargement de l'image du joueur: " << SDL_GetError() << endl;
}

font = TTF_OpenFont("data/Arial.ttf", 17);
if (font == nullptr)
        font = TTF_OpenFont("data/Arial.ttf", 17);
if (font == nullptr) {
        cerr << "Échec du chargement de la police:  " << TTF_GetError() << endl;
        SDL_Quit();
        exit(3);
    }
fontSaisie=TTF_OpenFont("data/Arial.ttf", 26);
    
    if (fontSaisie == nullptr)
        fontSaisie = TTF_OpenFont("data/Arial.ttf", 17);
if (fontSaisie == nullptr) {
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
     // Libération des textures et surfaces
    SDL_DestroyTexture(textureImage1);

    SDL_DestroyTexture(textureImage2);

    SDL_DestroyTexture(textureImageFond);

   SDL_FreeSurface( tempSurface);

   SDL_DestroyTexture(textTexture);
    SDL_FreeSurface(textSurface);//
    
    SDL_DestroyTexture(textInputTexture);
    SDL_FreeSurface(textInputSurface);

TTF_CloseFont(font); 
    TTF_CloseFont(fontSaisie); 
    // Libère la police
    SDL_DestroyRenderer(renderer); // Libère le renderer
    SDL_DestroyWindow(window); // Libère la fenêtre
 // Libération de SDL_ttf et SDL_image
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

}
/**
 * @brief Dessine les personnages (joueur et ennemi) sur l'écran.
*/
//
void Affichage::AfficherFond()
{
     int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
		//Positionnement et affichage d' imageBouton
		posFond.x = 0; //pas besoin 
		posFond.y= 0; //il faut ajouter w et h 
         posFond.w = windowWidth; 
    posFond.h = windowHeight;
	//SDL_QueryTexture(textureImageFond, NULL, NULL, &posFond.w, &posFond.h);//xem lai
	SDL_RenderCopy(renderer, textureImageFond,NULL, &posFond);
}
void Affichage::dessinerPersonnage(Joueur j, Ennemi ennemi)
{
    SDL_Rect posIma1;
    int nbEnnemi= ennemi.nbEnne();
     for (int i = 0; i < nbEnnemi; ++i) {
        posIma1.x  = ennemi.posXEnne(i);
        posIma1.y = ennemi.posYEnne(i);
        SDL_QueryTexture(textureImage1, NULL, NULL, &posIma1.w, &posIma1.h);//ko can 
		SDL_RenderCopy(renderer, textureImage1,NULL, &posIma1);
    }
		//Positionnement et affichage d'image ennemi
		/*SDL_Rect posIma1;
		posIma1.x = 100; //il faut mettre sur l'ennemi
		posIma1.y= 100;
		SDL_QueryTexture(textureImage1, NULL, NULL, &posIma1.w, &posIma1.h);//ko can 
		SDL_RenderCopy(renderer, textureImage1,NULL, &posIma1);
		*/
		//Positionnement et affichage d'image 2 joueur
	SDL_Rect posIma2;
		posIma2.x =j.getPosX() ; 
		posIma2.y= j.getPosY();
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
	//Ennemi ennemi;
   // int pointDeVieEnnemi= ennemi.getPointDeVieEnnemi(); 
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
 * @brief Affiche le texte sur l'écran.
 * @param renderer Pointeur vers le renderer SDL.
 * @param lignes Vecteur contenant les lignes de texte à afficher.
*/
 /* void Affichage::AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes)
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
}*/
void Affichage::AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes) {
    int posY = 10;
    int spacing = 5;
    for (size_t i = 0; i < lignes.size(); ++i) {
        textSurface = TTF_RenderText_Blended(font, lignes[i].c_str(), textColorInfo);
        if (textSurface == nullptr) {
            cerr << "Erreur lors du rendu du texte: " << TTF_GetError() << endl;
        } else {
            textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            if (textTexture == nullptr) {
                cerr << "Erreur lors de la création de la texture à partir de la surface: " << SDL_GetError() << endl;
            } else {
                SDL_Rect textRect = {310, posY, textSurface->w, textSurface->h};
                SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
                posY += textSurface->h + spacing;
            }
            SDL_FreeSurface(textSurface); // Giải phóng surface
            SDL_DestroyTexture(textTexture); // Giải phóng texture
        }
    }
}

/**
 * @brief Affiche les informations du joueur et de l'ennemi.
 * @param joueur Objet représentant le joueur.
 * @param ennemi Objet représentant l'ennemi.
*/
void Affichage::AfficherInfo(Joueur joueur, Ennemi ennemi, SDL_Renderer *renderer) {
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
     int windowWidth, windowHeight;
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);
		//Positionnement et affichage d' imageBouton
		posFond.x = 0; //pas besoin 
		posFond.y= 0; //il faut ajouter w et h 
         posFond.w = windowWidth; // Sử dụng chiều rộng của cửa sổ
    posFond.h = windowHeight;
	//SDL_QueryTexture(textureImageFond, NULL, NULL, &posFond.w, &posFond.h);//xem lai
	SDL_RenderCopy(renderer, textureImageFond,NULL, &posFond);
}

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
            else if (textInputActive == true) {
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
        }    else if (events.key.keysym.sym == SDLK_RETURN) { 
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

    if (!inputText.empty()) {
        textInputSurface = TTF_RenderText_Blended(fontSaisie, inputText.c_str(), {255, 255,0});
        if (textInputSurface == nullptr) {
            cerr << "! SDL_ttf Error: " << TTF_GetError() <<endl;
        } else {
            textInputTexture = SDL_CreateTextureFromSurface(renderer, textInputSurface);
            SDL_Rect textRect = {10, 450,textInputSurface->w, textInputSurface->h};

            SDL_RenderCopy(renderer, textInputTexture, NULL, &textRect);
        }
    }
}

/**
 * @brief Affiche le jeu en cours.
 * @param joueur Objet représentant le joueur.
 * @param ennemi Objet représentant l'ennemi.
 * @param jeu Objet représentant le jeu.
*/
void Affichage::AfficherJeu(Joueur joueur, Ennemi ennemi, Jeu jeu) {
    bool quitter = false;
    while (!quitter) {
        // Affichage des éléments du jeu
        SDL_RenderClear(renderer);
        AfficherFond();
       dessinerPersonnage(joueur, ennemi); 

        barres(joueur); 
        AfficherInfo(joueur, ennemi, renderer);
        
        GererEvenements();
        // AfficherTexteSaisie();
        
        // Affichage à l'écran
       SDL_RenderPresent(renderer);

        // Vérification si l'utilisateur veut quitter
        SDL_Delay(1200); 
    }
    
}
//ajouter sons
//joueur ne pas affiche pendant dialogue
//si il y a plus 1 ennemi et gerer la pos entre
//noeud //afficher comme dans le fichier Grapejeu.txt
			
			
