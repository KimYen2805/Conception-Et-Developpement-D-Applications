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
    FILE *fichier;
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
       
         void dessinerPersonnage(Joueur j, Ennemi ennemi);
        void barres(Joueur j);
        void CalculerDimensionsDuTexte(const vector<string>& lignes, int& largeurMax, int& hauteurTotale, vector<int>& hauteurs);
       // void DessinerFondTexte(SDL_Renderer* renderer,int largeurMax, int hauteurTotale);
        void AfficherTexte(SDL_Renderer* renderer,const vector<string>& lignes);
        void AfficherInfo(Joueur j, Ennemi enne, SDL_Renderer *renderer);
        //jeu 
        void AfficherJeu(Joueur j, Ennemi ennemi,Jeu jeu);
        void GererEvenements();
       
    void AfficherTexteSaisie();
       
     
 };

#endif
