#include "jeu.h"

Jeu::Jeu(const string &j){
    
    ifstream fichier(j.c_str());
    if(!fichier.is_open()){ cout<<"file not open"<<endl;
    }
    string nom, sort, neffet;
    int pvMx, mnMx;
    float coutS, puissanceEffet;
    Sort inSort[NBSORT];
    Effet effet;

    fichier >> nom >> pvMx >> mnMx ;
    for (int i = 0; i < NBSORT; ++i)
    {
            fichier >> sort >> coutS >> neffet >> puissanceEffet; 
            inSort[i].setNomSort(sort) ;
            inSort[i].setCout(coutS) ;
            effet.setNomEffet(neffet);
            effet.setPuissanceEffet(puissanceEffet);
            inSort[i].setEffetSort(effet);
    }
    
    joueur = Joueur(nom, pvMx, mnMx, inSort);
    
    fichier.close();
    cout << "Lecture du joueur " << j << " ... OK\n";

    Noeud Noeud(joueur); 
}

Joueur Jeu::getJoueur(){
    return joueur;
}

