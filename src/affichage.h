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
        TTF_Font *font;
        SDL_Color textColor;
         SDL_Color rectColor;
         SDL_Rect posBouton;
         SDL_Rect posFond;

 
    
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
         
       
         void dessinerPersonnage();
        void barres(Joueur j);
       // void texte (const vector<string>& lignes, int x, int y, int espacement);
        void CalculerDimensionsDuTexte(const vector<string>& lignes, int& largeurMax, int& hauteurTotale, vector<int>& hauteurs);
        void DessinerFondTexte(SDL_Renderer* renderer,int largeurMax, int hauteurTotale);
        void AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes);
      //  void AffichageTexte(SDL_Renderer* rend);
        void AfficherInfo(Joueur j, Ennemi enne);
        void AfficherJeu(Joueur j, Ennemi ennemi,Jeu jeu);
        void GererEvenements();

        void AfficherBoutonAction();
        void HandleMouseClick(SDL_Event event);
        void InitialiserRectBoutonAction();
        void Action(Joueur joueur);
        void AfficherFond();
};

#endif
