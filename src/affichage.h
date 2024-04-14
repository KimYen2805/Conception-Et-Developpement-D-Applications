//affichage.h
#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "jeu.h" 
#include "joueur.h"
#include "ennemi.h"
#include "graphe.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <sstream>



class Affichage {
        private:
    SDL_Window* window; /**< Fenêtre SDL */
    SDL_Renderer* renderer; /**< Renderer SDL */

    SDL_Texture* textureImage1; /**< Texture de l'image ennemi */
    SDL_Surface *image1; /**< Surface de l'image ennemi */

    SDL_Texture* textureImage2; /**< Texture de l'image joueur */
    SDL_Surface *image2; /**< Surface de l'image joueur */

   SDL_Texture* textureImageFond; /**< Texture de l'image de fond */
    SDL_Surface *imageFond; /**< Surface de l'image de fond */

    SDL_Surface* tempSurface; /**< Surface temporaire */

    SDL_Texture* textTexture; /**< Texture du texte */
    SDL_Surface* textSurface; /**< Surface du texte */

    SDL_Rect posFond; /**< Position de l'image de fond */

    bool textInputActive = false; /**< Indicateur d'entrée de texte */

    TTF_Font* font; /**< Police de caractères */
    TTF_Font *fontSaisie; /**< Police de caractères pour la saisie */

    SDL_Color textColorInfo; /**< Couleur du texte */
    SDL_Color rectColor; /**< Couleur du rectangle */

    SDL_Rect inputRect; /**< Rectangle de saisie */
    string inputText; /**< Texte saisi */
    SDL_Surface* textInputSurface; /**< Surface de texte saisi */
    SDL_Texture* textInputTexture; /**< Texture de texte saisi */

    bool renderText = false; /**< Indicateur d'affichage de texte */
    //bool besoinDeNettoyer = false; /**< Indicateur de besoin de nettoyage */
     Noeud* n;
     vector<Noeud*> sommets;
    vector<pair<Noeud*,Noeud*>> aretes;
//bool quitter = false;
string pTexte;
bool effacerTexte = false; 

//SDL_Rect texteRectA;
        public:
        /**
         * @brief Constructeur
         * renvoie une fenêtre SDL
        */
         Affichage();
        /**
         * @brief Destructeur
         * Libère toutes les ressources allouées par l'objet Affichage, y compris la fenêtre SDL, le renderer, les textures et les surfaces.
        */
        ~Affichage();
        /**
         * @brief Affiche l'image dans la fenêtre
        */
        void AfficherFond();
        /**
         * @brief Dessine les personnages (joueur et ennemi) sur l'écran.
        */
        void dessinerPersonnage(Joueur j, Ennemi ennemi);
        /**
         * @brief Affiche les barres de santé et de mana du joueur.
         * @param joueur Objet représentant le joueur.
        */
        void barres(Joueur j,SDL_Renderer* renderer);
        /**
         * @brief Calcule les dimensions du texte à afficher.
         * @param li Vecteur contenant les lignes de texte.
         * @param larMax Référence à la largeur maximale du texte.
         * @param hautTotale Référence à la hauteur totale du texte.
         * @param haut Vecteur contenant les hauteurs de chaque ligne de texte.
        */
        void CalculerDimensionsDuTexte(const vector<string>& lignes, int& largeurMax, int& hauteurTotale, vector<int>& hauteurs);
       // void DessinerFondTexte(SDL_Renderer* renderer,int largeurMax, int hauteurTotale);
       /**
         * @brief Affiche le texte sur l'écran.
         * @param renderer Pointeur vers le renderer SDL.
         * @param lignes Vecteur contenant les lignes de texte à afficher.
        */
        void AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes, const SDL_Rect& rect);
        /**
         * @brief Affiche les informations du joueur et de l'ennemi.
         * @param joueur Objet représentant le joueur.
         * @param ennemi Objet représentant l'ennemi.
        */
        void AfficherInfo(Joueur j, Ennemi enne, SDL_Renderer *renderer);
       
     //   void GererEvenements();
       void effacerEtAfficherTexte(SDL_Renderer* renderer, const SDL_Rect& rect);
    //void AfficherTexteSaisie();

    void chargerGrapeJeu();
  void handleInput(string &pTexte);
     void playGame(SDL_Renderer* renderer);

      //jeu 
        void AfficherJeu(Joueur j, Ennemi ennemi);
 };

#endif