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
window=SDL_CreateWindow("ProjetCDKA",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,820,750,SDL_WINDOW_SHOWN);

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

font = TTF_OpenFont("data/Arial.ttf", 20);
if (font == nullptr)
        font = TTF_OpenFont("data/Arial.ttf", 17);
if (font == nullptr) {
        cerr << "Échec du chargement de la police:  " << TTF_GetError() << endl;
        SDL_Quit();
        exit(3);
    }

	// Initialisation des couleurs 
    textColorInfo = {255, 255,0};
    rectColor = {0, 0, 0};
    pTexte = ""; 
    
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
         posFond.w = windowWidth; 
    posFond.h = windowHeight;
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
		//Positionnement et affichage d'image 2 joueur
	SDL_Rect posIma2;
		posIma2.x =j.getPosX() ; 
		posIma2.y= j.getPosY();
	SDL_QueryTexture(textureImage2, NULL, NULL, &posIma2.w, &posIma2.h);
	SDL_RenderCopy(renderer, textureImage2,NULL, &posIma2);

}
void Affichage:: barres(Joueur joueur , SDL_Renderer* renderer)
{
    // Récupération des données du joueur
	int pointDeVieJoueur = joueur.getPVJoueur(); // Point de vie du joueur
    int maxManaJoueur = joueur.getMana()*100/joueur.getMAXMana();    // Mana maximale du joueur
// Affichage de la barre de vie du joueur
	SDL_Rect rePo; 
		rePo.x =600; 
		rePo.y =600;
		rePo.w = pointDeVieJoueur;
		rePo.h =15;
	SDL_SetRenderDrawColor(renderer,255,0,0,0);
	SDL_RenderFillRect(renderer, &rePo);
		// Affichage de la barre de mana du joueur
		SDL_Rect reMa; 
		reMa.x =600; 
		reMa.y =620;
		reMa.w = maxManaJoueur;
		reMa.h =15;
	SDL_SetRenderDrawColor(renderer,0,0,255,0);
	SDL_RenderFillRect(renderer, &reMa);

}
/**
 * @brief Affiche les barres de santé et de mana du joueur.
 * @param joueur Objet représentant le joueur.
*/

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

void Affichage::AfficherTexte(SDL_Renderer* renderer, const vector<string>& lignes, const SDL_Rect &rect) {
    int posY = rect.y;
    int spacing = 5;

    for (size_t i = 0; i < lignes.size(); ++i) {
        vector<string> sublines;
        istringstream iss(lignes[i]);
        string subline;
        while (getline(iss, subline, '\n')) {
            sublines.push_back(subline);
        }
        for (const auto& subline : sublines) {
            textSurface = TTF_RenderText_Blended(font, subline.c_str(), textColorInfo);
            if (textSurface == nullptr) {
                cerr << "Erreur lors du rendu du texte: " << TTF_GetError() << endl;
            } else {
                textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
                if (textTexture == nullptr) {
                    cerr << "Erreur lors de la création de la texture à partir de la surface: " << SDL_GetError() << endl;
                } else {
                    SDL_Rect textRect = {rect.x, posY, textSurface->w, textSurface->h};
                    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
                    posY += textSurface->h + spacing;
                }
                SDL_FreeSurface(textSurface); 
                SDL_DestroyTexture(textTexture); 
            }
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
        "Bienvenue dans notre jeu! Pour commencer, appuyez sur Entree.",
        "Nom du joueur : " + joueur.getNomJoueur()
    };
     SDL_Rect textRect = {200, 10, 0, 0};
    // Appeler la fonction d'affichage du texte
   AfficherTexte(renderer, lignes, textRect);
}

void Affichage::chargerGrapeJeu()
{ ifstream fichG("data/GrapheJeu.txt");
    if(!fichG.is_open())
    { 
        std::cout<<"file not open graphe"<<endl;
        exit(EXIT_FAILURE);
    }
    int fils;
    int ind=0;
    int nbL;
    

    string nomN, texte, rep;
    char separator;
    string reponse[MAXREP];
    int NBNOEUD;
    fichG >> NBNOEUD;
    for (int i=0;i<NBNOEUD;i++)
    {
        fichG >> ind >> nomN >> separator;    
        std::cout<<ind<<" "<<nomN<<" "<< separator<< endl;
        if(separator=='d')
        {
            string temp;
            fichG >> nbL >> rep;
            getline(fichG, temp);
            texte = rep + temp;
            for(int i=0; i<nbL-1;i++)
            {
                getline(fichG, temp);
                texte+='\n'+temp; 
            }
            std::cout<<texte<<endl;
            fichG >> fils;
            std::cout<<fils;
            for (int i=0;i<fils;i++)
            {
                fichG >> reponse[i];
                std::cout<<" "<<reponse[i];
            }
            std::cout<< endl;
            
            sommets.push_back(new Dialogue(ind,nomN,texte,reponse,fils,separator));
        }

        if(separator=='c')
        {
            Ennemi tab[MAXENNEMI];
            fichG >> fils;
            std::cout<<fils;
            for (int i=0;i<fils;i++)
            {
                int pv, mana, nbS;
                fichG >> pv>>mana>>nbS;

                std::cout<<" "<<pv <<" "<<mana;
            

                tab[i].setPointDeVieEnnemi(pv);
                tab[i].setPuissanceEnnemi(mana);
                for (int j=0;j<nbS;j++)
                {
                    int iSort;
                    fichG>>iSort;
                    tab[i].addSort(iSort);
                }
                
            }
           // std::cout<< endl;
            sommets.push_back(new Combat(tab,fils,ind,nomN,separator));
        }

    }
    fichG>>fils;
    std::cout<<"Fin noeuds "<<fils<<endl;
    for (int i=0;i<fils;i++){
        int ad1, ad2;
        fichG>>ad1>> ad2;
        aretes.push_back(pair(sommets[ad1],sommets[ad2]));
        std::cout<<ad1<<" - "<<ad2<<endl;
        
    }
            
    fichG.close();
   // std::cout << "Lecture du fichier " << g << " ... OK\n";
    n=sommets[0];
}

void Affichage::handleInput(string &pTexte) {
        bool inputComplete = false;
           SDL_Event event;
   SDL_StartTextInput();
    while (!inputComplete) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                inputComplete = true;
                SDL_Quit();
                exit(0);
                break;
            }
            if (event.type == SDL_KEYDOWN) {
                 if (event.key.keysym.sym == SDLK_ESCAPE) {
                SDL_Quit();
                exit(0);
            } 
                if (event.key.keysym.sym == SDLK_BACKSPACE && pTexte.length() > 0) {
                    pTexte.pop_back();
                } else if (event.key.keysym.sym == SDLK_RETURN) {
                    inputComplete = true;
                    effacerTexte= true;
                    // pTexte = ""; 
                }
            } 
            else if (event.type == SDL_TEXTINPUT) {
             if (!(SDL_GetModState() & KMOD_CTRL && (event.text.text[0] == 'c' || event.text.text[0] == 'C' || event.text.text[0] == 'v' || event.text.text[0] == 'V'))) {
                pTexte += event.text.text;
            }
            }  else if (event.key.keysym.sym == SDLK_RETURN) { 
                pTexte = ""; 
                //effacerTexte= true;
    }
        }
        SDL_Rect texteRect = { 50, 450, 100, 50 };
        SDL_SetRenderDrawColor(renderer, 231, 76, 60, 255); 
        SDL_RenderFillRect(renderer, &texteRect);

        AfficherTexte(renderer, { pTexte }, texteRect);

       SDL_RenderPresent(renderer);
    }
    SDL_StopTextInput();
}
void Affichage::effacerEtAfficherTexte(SDL_Renderer* renderer, const SDL_Rect& rect) {
    SDL_SetRenderDrawColor(renderer, 97, 106, 107, 255); 
    SDL_RenderFillRect(renderer, &rect);

    vector<string> lignes = { " " }; 
    AfficherTexte(renderer, lignes, rect);
}

void Affichage::playGame(SDL_Renderer* renderer) {
    Jeu Jeu;
    Joueur joueur = Jeu.getJoueur();
    Noeud* noeud = Jeu.getCNoeud();

    SDL_Rect texteRectA = { 10, 300, 820, 130 };
    Dialogue* d;
    Combat* c;

    while (!Jeu.getGraphe().isFeuille(noeud)) {
        if (noeud->getDelim() == 'd') {
            d = (Dialogue*)noeud;
            int isValid = -1;
            vector<string> lignes;
            while (isValid == -1) {
                lignes = { d->getTexte() };
                AfficherTexte(renderer, lignes, texteRectA);
                handleInput(pTexte);
                if (effacerTexte) {
                    effacerEtAfficherTexte(renderer, texteRectA);
                    effacerTexte = false;
                }
                if (pTexte == "Aide") {
                    vector<string> aide = { d->getRep() };
                    AfficherTexte(renderer, aide, texteRectA);
                    handleInput(pTexte);
                     if (effacerTexte) {
                            effacerEtAfficherTexte(renderer, texteRectA);
                            effacerTexte = false;
                        }
                } else {
                    isValid = d->rep(pTexte);
                    if (isValid != -1) {
                        Jeu.getGraphe().parcoursGraphe(isValid);
                    } else {
                        vector<string> reponse = { "Reponse invalide au dialogue" };
                        AfficherTexte(renderer, reponse, texteRectA);
                        handleInput(pTexte);
                        if (effacerTexte) {
                            effacerEtAfficherTexte(renderer, texteRectA);
                            effacerTexte = false;
                        }
                    }
                }
            }
        } else if (noeud->getDelim() == 'c') {
            c = (Combat*)noeud;
              
            while (c->isFight(joueur) == -1) {
                vector<string> lignesStat;
                c->affStatSDL(joueur, lignesStat);
                AfficherTexte(renderer, lignesStat, texteRectA);

                int target = 0;
                vector<string> message = { "Action joueur:" };
                AfficherTexte(renderer, message, { 350, 220, 100, 50 });
                handleInput(pTexte);
                if (effacerTexte) {
                    effacerEtAfficherTexte(renderer, texteRectA);
                    effacerTexte = false;
                }
                if (isdigit(pTexte[0])) {
                    target = pTexte[0] - '0';
                    pTexte.erase(0, 1);
                }
                vector<string> lignesSort;
                int iSort = c->castSortSDL(joueur, pTexte, lignesSort);
                AfficherTexte(renderer, lignesSort, { 300, 300, 100, 50 });
                     if (effacerTexte) {
                            effacerEtAfficherTexte(renderer, texteRectA);
                            effacerTexte = false;
                        }
                if (iSort != -1) {
                    c->playTurnSDL(joueur, iSort, target, lignesSort);
                     AfficherTexte(renderer, lignesSort, { 300, 300, 100, 50 });
                }
                if (c->isFight(joueur) == -1) {
                    c->ennTurn(joueur);
                  
                }
                AfficherTexte(renderer, lignesSort, { 300, 300, 100, 50 });
                  handleInput(pTexte);
                 if (effacerTexte) {
                            effacerEtAfficherTexte(renderer, texteRectA);
                            effacerTexte = false;
                        }
                         barres(joueur, renderer);
            }
            Jeu.getGraphe().parcoursGraphe(c->isFight(joueur));
        }
        
        noeud = Jeu.getCNoeud(); // Avancer dans le jeu en fonction des résultats
    }

    d = (Dialogue*)noeud;
     vector<string> messageV = { "Win" };
    AfficherTexte(renderer, messageV, { 350, 320, 100, 50 }); //Dialogue de fin
    handleInput(pTexte);
    if (effacerTexte) {
        effacerEtAfficherTexte(renderer, texteRectA);
        effacerTexte = false;
    }
}

/**
 * @brief Affiche le jeu en cours.
 * @param joueur Objet représentant le joueur.
 * @param ennemi Objet représentant l'ennemi.
 * @param jeu Objet représentant le jeu.
*/

void Affichage::AfficherJeu(Joueur joueur, Ennemi ennemi) {
    bool quitter = false;
            
    while (!quitter) {
        // Affichage des éléments du jeu
       //SDL_RenderClear(renderer);
        AfficherFond();
          AfficherInfo(joueur, ennemi, renderer);
       dessinerPersonnage(joueur, ennemi); 
       
        handleInput(pTexte);
         playGame(renderer);
      //  barres(joueur,renderer);  
        // Affichage à l'écran
       SDL_RenderPresent(renderer);

        // Vérification si l'utilisateur veut quitter
        SDL_Delay(1000); 
    }
    
}

//ajouter sons
//joueur ne pas affiche pendant dialogue
			
			
