#include "jeu.h"

Graphe::Graphe()
{
    const string &g="./data/GrapheJeu.txt";
    ifstream fichG(g.c_str());
    if(!fichG.is_open())
    { 
        //std::cout<<"file not open graphe"<<endl;exit(EXIT_FAILURE);
    }
    int fils;
    int ind=0;
    

    string nomN, texte, rep;
    char separator;
    string reponse[MAXREP];
    int NBNOEUD;
    fichG >> NBNOEUD;
    for (int i=0;i<NBNOEUD;i++)
    {
        fichG >> ind  >> nomN>> separator;    
        //std::cout<<ind<<" "<<nomN<<" "<< separator<< endl;
        if(separator=='d')
        {
            fichG >> rep;
            getline(fichG, texte);
            texte = rep + texte;
            //std::cout<<texte<<endl;
            fichG >> fils;
            //std::cout<<fils;
            for (int i=0;i<fils;i++)
            {
                fichG >> reponse[i];
                //std::cout<<" "<<reponse[i];
            }
            //std::cout<< endl;
            
            sommets.push_back(new Dialogue(ind,nomN,texte,reponse,fils,separator));
        }

        if(separator=='c')
        {
            Ennemi tab[MAXENNEMI];
            fichG >> fils;
            //std::cout<<fils;
            for (int i=0;i<fils;i++)
            {
                int pv, mana, nbS;
                fichG >> pv>>mana>>nbS;

                //std::cout<<" "<<pv <<" "<<mana;
                tab[i].setPointDeVieEnnemi(pv);
                tab[i].setPuissanceEnnemi(mana);
                for (int j=0;j<nbS;j++)
                {
                    int iSort;
                    fichG>>iSort;
                    tab[i].addSort(iSort);
                }
                
            }
            //std::cout<< endl;
            sommets.push_back(new Combat(tab,fils,ind,nomN,separator));
        }

    }
    fichG>>fils;
    //std::cout<<"Fin noeuds "<<fils<<endl;
    for (int i=0;i<fils;i++){
        int ad1, ad2;
        fichG>>ad1>> ad2;
        aretes.push_back(pair(sommets[ad1],sommets[ad2]));
        //std::cout<<ad1<<" - "<<ad2<<endl;
        
    }

    
    fichG.close();
    //std::cout << "Lecture du fichier " << g << " ... OK\n";
    n=sommets[0];
   
}

Graphe::~Graphe()
{
    for (long unsigned int i=0;i<sommets.size();i++)
    {
        //cout<<sommets[i]<<" "<<i<<endl;
        delete sommets[i];
    }
}

Noeud* Graphe::getNoeud(){
    //cout<<"dans graphe"<<endl;
    return n;
}

void Graphe::parcoursGraphe(int id){
    for(long unsigned int i=0;i<aretes.size();i++){

        if (aretes[i].first->getID() == this->n->getID()){
            if (aretes[i].first->getID()==aretes[i+id].first->getID())
            {
                n=aretes[i+id].second;
                //cout<<n->getID()<<endl;;
                break;
            }//else{//cout<<"pas de fils "<<i<<endl; }
        }//else{//cout<<"pas de père "<<i<<endl; }
    }
}

bool Graphe::isFeuille(Noeud* nActu)
{
    for(long unsigned int i=0;i<aretes.size();i++){

        if (aretes[i].first->getID() == this->n->getID()){
            return false;
        }
    }
    return true;
}