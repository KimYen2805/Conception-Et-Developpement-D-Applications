#include "jeu.h"

Jeu::Jeu(const string &j, const string &g){
    
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
    ifstream fichG(g.c_str());
    if(!fichG.is_open()){ cout<<"file not open"<<endl;
    
    string nom, texte, separator, rep;
    string reponse[MAXREP];
    int ind;
    int indice[MAXREP];

    fichG >> ind >> separator >> nom;

    if(separator=="d")
    {
        getline(fichG, texte);
        int i=0;
        fichG >> rep;
        while(rep!="cap"){
            cout<<rep<<" "<<ind<<" "<<endl;
            fichG>>ind;
            indice[i]=ind;
            reponse[i]=rep;
            i++;
            fichG >> rep;
        }
        
        
    }
    cout<<ind<<separator<<nom;
    }
    fichG.close();
    cout << "Lecture du fichier " << g << " ... OK\n";

}

Joueur Jeu::getJoueur(){
    return joueur;
}

