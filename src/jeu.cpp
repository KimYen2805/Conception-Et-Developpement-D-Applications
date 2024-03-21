#include "jeu.h"

Jeu::Jeu(){
    const string &j="./data/Joueur";
    ifstream fichJ(j.c_str());
    if(!fichJ.is_open()){ std::cout<<"file not open"<<endl;exit(EXIT_FAILURE);
    }
    
    string nom, sort, neffet;
    int pvMx, mnMx;
    float coutS, puissanceEffet;
    Sort inSort[NBSORT];
    Effet effet;

    fichJ >> nom >> pvMx >> mnMx ;
    for (int i = 0; i < NBSORT; ++i)
    {
            fichJ >> sort >> coutS >> neffet >> puissanceEffet; 
            inSort[i].setNomSort(sort) ;
            inSort[i].setCout(coutS) ;
            effet.setNomEffet(neffet);
            effet.setPuissanceEffet(puissanceEffet);
            inSort[i].setEffetSort(effet);
    }
    
    joueur = Joueur(nom, pvMx, mnMx, inSort);
    
    fichJ.close();
    std::cout << "Lecture du fichier " << j << " ... OK\n";
//----------------------------------------------------------------------------------------------------------------------------------------------------
}

Joueur Jeu::getJoueur(){
    return joueur;
}

