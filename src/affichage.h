//affichage.h
#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "jeu.h" 
#include "joueur.h"
#include "ennemi.h"
#include <SDL2/SDL.h>


class ImageAffichage {
        private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        public:
/**
 * @brief Constructeur
*/
         ImageAffichage();
    /**
     * @brief Destructeur
    */
        ~ImageAffichage();
/**
 * @brief Affiche l'image dans la fenêtre
*/
         void Afficher(Joueur j);
};

#endif
