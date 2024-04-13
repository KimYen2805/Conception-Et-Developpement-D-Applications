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
/*void Affichage::AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes, const SDL_Rect &rect) {
std::stringstream ss(lignes);
    string line;
 int posY = rect.y;
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
                SDL_Rect textRect = {rect.x, posY, textSurface->w, textSurface->h};
                SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
                posY += textSurface->h + spacing;
            }
            SDL_FreeSurface(textSurface); // Giải phóng surface
            SDL_DestroyTexture(textTexture); // Giải phóng texture
        }
    }
}*/
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
        "Nom du joueur : " + joueur.getNomJoueur(),
        "Point de vie : " + to_string(joueur.getPVJoueur()),
        "Max mana : " + to_string(joueur.getMana() * 100 / joueur.getMAXMana()),
        "Point de vie ennemi : " + to_string(ennemi.getPointDeVieEnnemi())
    };
     SDL_Rect textRect = {300, 10, 0, 0};
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
            std::cout<< endl;
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

void Affichage::handleInput(string &pTexte) {
    bool enterPressed = false;
        bool inputComplete = false;
         SDL_StartTextInput();
   SDL_StartTextInput();
    while (!inputComplete) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                inputComplete = true;
                SDL_Quit();
                exit(0);
                break;
            }
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_BACKSPACE && pTexte.length() > 0) {
                    pTexte.pop_back();
                } else if (event.key.keysym.sym == SDLK_RETURN) {
                    inputComplete = true;
                }
            } else if (event.type == SDL_TEXTINPUT) {

                pTexte += event.text.text;
            }
        }
        AfficherTexte(renderer, { pTexte }, { 50, 100, 400, 100 });

        SDL_RenderPresent(renderer);
    }
    SDL_StopTextInput();
}
void Affichage::playGame(SDL_Renderer* renderer) {
    Jeu Jeu;
    Joueur joueur=Jeu.getJoueur();
    Noeud* noeud;
    noeud=Jeu.getCNoeud();

    string pTexte; //Les futurs réponses du joueur dans le main;
    Dialogue* d;
    Combat* c;
        while (!Jeu.getGraphe().isFeuille(noeud)) {
        if (noeud->getDelim() == 'd') {
            d = (Dialogue*)noeud;
            vector<string> lignes = { d->getTexte() };
           AfficherTexte(renderer, lignes, { 10, 300, 300, 50 });
            handleInput(pTexte);
            //cout<<d->getTexte()<<endl<<"Choix : ";
              //  cin>>pTexte;
            if (pTexte == "Aide") {
                vector<string> aide = { d->getRep() };
                AfficherTexte(renderer, aide, { 10, 200, 300, 50 });
            //  cout<<d->getRep()<<endl;
            }
            else {
                int isValid = d->rep(pTexte);
                if (isValid != -1) {
                    Jeu.getGraphe().parcoursGraphe(isValid);
                }
                else {
                    vector<string> reponse = { "Reponse invalide au dialogue" };
                    AfficherTexte(renderer, reponse, { 10, 200, 500, 50 });
                   // cout<<"Reponse invalide au dialogue"<<endl;
                }
            }
        }
       else if (noeud->getDelim() == 'c') {
            
                c=(Combat*) noeud;
            while(c->isFight(joueur)==-1)
            {   
                c->affStat(joueur);
                int target =0;
                cout<<endl<<"Action joueur: ";
                // cin>>pTexte;
               handleInput(pTexte);
                if (isdigit(pTexte[0]))
                {
                    target=pTexte[0]-'0'; 
                    pTexte.erase(0,1);
                }
                int iSort = c->castSort(joueur, pTexte);
                
                if (iSort!=-1)
                {
                    c->playTurn(joueur,iSort, target);
                }
                if(c->isFight(joueur)==-1)
                {
                    c->ennTurn();
                }
                
            }
            Jeu.getGraphe().parcoursGraphe(c->isFight(joueur));

        }

        noeud = Jeu.getCNoeud(); //avancer dans le jeu en fonction des résultats
      
    }

    d = (Dialogue*)noeud;
    vector<string> lignes = { d->getTexte() };
    AfficherTexte(renderer, lignes, { 10, 10, 500, 50 }); //Dialogue de fin

}
/**
 * @brief Affiche le texte saisi par l'utilisateur.
*/
void Affichage::AfficherTexteSaisie() {

    if (textInputActive && !inputText.empty() && renderText) {
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
         playGame(renderer);
           //GererEvenements();
        // Affichage à l'écran
       SDL_RenderPresent(renderer);

        // Vérification si l'utilisateur veut quitter
        SDL_Delay(1200); 
    }
    
}
//ajouter sons
//joueur ne pas affiche pendant dialogue
			
			
