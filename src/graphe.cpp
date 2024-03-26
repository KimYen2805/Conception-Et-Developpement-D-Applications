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
    for (int i=0;i<4;i++)
    {
        fichG >> ind  >> nomN>> separator;    
        std::cout<<ind<<" "<<nomN<<" "<< separator<< endl;
        if(separator=="d")
        {
            fichG >> rep;
            getline(fichG, texte);
            texte = rep + texte;
            std::cout<<texte<<endl;
            fichG >> fils;
            std::cout<<fils;
            for (int i=0;i<fils;i++)
            {
                fichG >> reponse[i];
                std::cout<<" "<<reponse[i];
            }
            std::cout<< endl;
            
            sommets.push_back(new Dialogue(ind,nomN,texte,reponse,fils));
        }

        if(separator=="c")
        {
            Ennemi tab[MAXENNEMI];
            fichG >> fils;
            std::cout<<fils;
            for (int i=0;i<fils;i++)
            {
                int pv, mana, nbS;
                fichG >> pv>>mana>>nbS;

                std::cout<<" "<<pv <<" "<<mana;
                tab[i].setPointDeVieEnnemi(pv);
                tab[i].setPuissanceEnnemi(mana);
                for (int j=0;j<nbS;j++)
                {
                    int iSort;
                    fichG>>iSort;
                    tab[i].addSort(iSort);
                }
                
            }
            std::cout<< endl;
            sommets.push_back(new Combat(tab,fils,ind,nomN));
        }

    }
    fichG>>fils;
    for (int i=0;i<fils;i++){
        int ad1, ad2;
        fichG>>ad1>> ad2;
        aretes.push_back(pair(sommets[ad1],sommets[ad2]));
        std::cout<<ad1<<" "<<ad2<<endl;
    }

    
    fichG.close();
    std::cout << "Lecture du fichier " << g << " ... OK\n";
    n=sommets[0];
   
}

Graphe::~Graphe()
{
    for (long unsigned int i=0;i<sommets.size();i++)
    {
        delete sommets[i];
    }
}