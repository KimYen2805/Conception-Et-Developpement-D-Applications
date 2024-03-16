// mainTest.cpp

#include "joueur.h"
#include "ennemi.h"

//#include "jeu.h"



int main() {
    // Test Joueur
    Joueur joueur("./data/Joueur");
    joueur.testRegression();  

    cout << "\nInformations sur le Joueur : " << endl;
    cout << "Nom du Joueur : " << joueur.getNomJoueur() << endl;
    cout << "Points de vie du Joueur : " << joueur.getPVJoueur() << endl;
    cout << "Mana du Joueur : " << joueur.getMana() << endl;

    // Test Ennemi
    Ennemi ennemi;
    
    cout << "\nInformations sur l'Ennemi avant l'attaque : " << endl;
    cout << "Points de vie de l'Ennemi : " << ennemi.getPointDeVieEnnemi() << endl;
    cout << "Puissance de l'Ennemi : " << ennemi.getPuissanceEnnemi() << endl;

    //ennemi.attaquerJoueur();  // Simuler une attaque de l'ennemi

    cout << "\nInformations sur l'Ennemi apres l'attaque : " << endl;
    cout << "Points de vie de l'Ennemi : " << ennemi.getPointDeVieEnnemi() << endl;

    return 0;
}
