#include "jeu.h"

Jeu::Jeu(){
    const string &j="./data/Joueur";
    ifstream fichJ(j.c_str());
    if(!fichJ.is_open()){ cout<<"file not open"<<endl;
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
    cout << "Lecture du fichier " << j << " ... OK\n";
//----------------------------------------------------------------------------------------------------------------------------------------------------
    const string &g="./data/GrapheJeu";
    ifstream fichG(g.c_str());
    if(!fichG.is_open()){ cout<<"file not open"<<endl;
    int i, fils, ind=0;

    int* indice[MAXREP];

    string nom, texte, separator, rep;
    string reponse[MAXREP];
    
    fichG >> ind >> separator >> nom;
    cout<<ind<<separator<<nom;
    if(separator=="d")
    {
        getline(fichG, texte);
        int j=0;
        fichG >> rep;
        while(rep!="cap"){

            std::cout<<rep<<" "<<fils<<" "<<endl;
            fichG>>fils;

            indice[j]=&fils;
            reponse[j]=rep;
            j++;
            fichG >> rep;
        }
        
        
    }
    
    }
    fichG.close();
    cout << "Lecture du fichier " << g << " ... OK\n";

}

Joueur Jeu::getJoueur(){
    return joueur;
}

