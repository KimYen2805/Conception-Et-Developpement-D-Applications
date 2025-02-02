// mainTest.cpp
#include <iostream>
#include <thread>
#include <chrono>
#include "joueur.h"
#include "ennemi.h"

//#include "jeu.h"

/*string getVal(string defaultValue)
{
    string t="";
    thread enter([&]{cin>>t;});
    thread timer(chrono::seconds(3));
    
    while (!timer.joinable()||!enter.joinable())
    {

    }
    enter.join();
    return t;

}*/


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
    //tests supplémentaires en utilisant cin
    string choix;
    cout << "\nMenu de test :" << endl;
    cout << "1. Effectuer une action" << endl;
    cout << "2. Quitter" << endl;
    bool c=false;
    while(c==false){
        
    cout << "Votre choix : ";
    //choix= getVal("123");
    cin>>choix;

    if (choix=="Action"){ 
        cout<<"choix 1: action"<<endl;
        c=true;
    }else if (choix=="Quitter"){
        cout<<"choix 2: quitter"<<endl;
        c=true;
    }else{
        cout << choix<<"Choix invalide. Veuillez choisir à nouveau." << endl;
    }
    }

    return 0;
}


