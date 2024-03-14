#include "jeu.h"

Jeu::Jeu(const string &filename){
    
    ifstream fichier(filename.c_str());
    if(!fichier.is_open()){ cout<<"file not open"<<endl;
    }else{
    string nom, sort, effet;
    int pvMx, mnMx;
    float coutS, puissanceEffet;
    Sort inSort[NBSORT];
    
    fichier >> nom >> pvMx >> mnMx ;

    for (int i = 0; i < NBSORT; ++i)
    {
            fichier >> sort >> coutS >> effet >> puissanceEffet; 
            
            inSort[i].setNomSort(sort) ;
            inSort[i].setCout(coutS) ;
            inSort[i].getEffetSort().setNomEffet(effet) ;
            inSort[i].getEffetSort().setPuissanceEffet(puissanceEffet) ;
    }
    Joueur(nom, pvMx, mnMx, inSort);
    fichier.close();
    cout << "Lecture du joueur " << filename << " ... OK\n";
    }
}

