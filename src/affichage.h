//affichage.h
#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "jeu.h" 
#include "joueur.h"
#include "ennemi.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>


class Affichage {
        private:
        SDL_Window* window;
    SDL_Renderer* renderer;

    SDL_Texture* textureImage1;
    SDL_Surface *image1;//

    SDL_Texture* textureImage2;
    SDL_Surface *image2;//

    SDL_Texture* textureImageFond;
    SDL_Surface *imageFond;//

    SDL_Surface* tempSurface;//

    SDL_Texture* textTexture;//
    SDL_Surface* textSurface ;

    SDL_Rect posFond;
   

    SDL_Rect posBouton;
    SDL_Surface *imageBouton;
    SDL_Texture *textureImageBouton;
    bool boutonClique = false;
    //

    TTF_Font* font;//

    SDL_Color textColor;
    SDL_Color rectColor;

    SDL_Rect inputRect;
    std::string inputText;
     SDL_Surface* textInputSurface ;
 SDL_Texture* textInputTexture;//
 
    
        public:
/**
 * @brief Constructeur
*/
         Affichage();
    /**
     * @brief Destructeur
    */
        ~Affichage();
/**
 * @brief Affiche l'image dans la fenêtre
*/
          void AfficherFond();
       
         void dessinerPersonnage();
        void barres(Joueur j);
       // void texte (const vector<string>& lignes, int x, int y, int espacement);
        void CalculerDimensionsDuTexte(const vector<string>& lignes, int& largeurMax, int& hauteurTotale, vector<int>& hauteurs);
        void DessinerFondTexte(SDL_Renderer* renderer,int largeurMax, int hauteurTotale);
        void AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes);
        void AfficherInfo(Joueur j, Ennemi enne);
        //jeu 
        void AfficherJeu(Joueur j, Ennemi ennemi,Jeu jeu);
        void GererEvenements();

        void AfficherBoutonAction();
        void HandleMouseClick(SDL_Event event);
        //void InitialiserRectBoutonAction();
      //  void Action(Joueur joueur);
       //gérer la boîte de texte
       // Déclaration de la fonction InitTextInputPosition
   // SDL_Rect InitTextInputPosition(int x, int y, int width, int height);
      //void InitTextInput();
    void DessinerTextInput();
       //void HandleTextInputEvent(SDL_Event event);
        //
};

#endif
