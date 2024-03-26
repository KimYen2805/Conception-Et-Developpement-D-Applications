#include "jeu.h"

Graphe::Graphe()
{
    const string &g="./data/GrapheJeu";
    ifstream fichG(g.c_str());
    if(!fichG.is_open())
    { 
        std::cout<<"file not open"<<endl;exit(EXIT_FAILURE);
    }
    int fils;
    int ind=0;

    int indice[MAXREP];

    string nomN, texte, separator, rep;
    string reponse[MAXREP];

    fichG >> ind  >> nomN>> separator;    
    std::cout<<ind<<" "<<nomN<<" "<< separator<< endl;
    fichG >> rep;
    getline(fichG, texte);
    texte = rep + texte;
    std::cout<<texte<<endl;
    fichG >> fils;
    for (int i;i<fils;i++){
        fichG >> reponse[i];
    }
     ;
    std::cout<<fils <<" "<<reponse[0] << " "<< reponse[1]<< endl;

/*
    //fichG >> re
    if(separator=="d")
    {
        getline(fichG, texte);
        std::cout<<"pa"<<texte<<'\n';
        int j= 0;
        fichG >> rep >> fils;
        while(rep!="cap"){
            std::cout<<rep<<", "<<fils<<", "<<endl;
            fichG>>fils;

            indice[j]=fils;
            reponse[j]=rep;
            j++;
            fichG >> rep;
        }
    }    
        */
    
    
    fichG.close();
    std::cout << "Lecture du fichier " << g << " ... OK\n";

    
}