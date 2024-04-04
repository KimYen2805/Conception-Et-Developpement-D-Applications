#include "jeu.h"
#include <iostream>
using namespace std;

int main()
{
    Jeu Jeu;

    Noeud* noeud;
    

    string pTexte; //Les futurs réponses du joueur dans le main;
    Dialogue* d;
    Combat* c;

    while(!Jeu.getGraphe().isFeuille(noeud))
    {
        if (noeud->getDelim()=='d')
        {
            d=(Dialogue*) noeud;
            cout<<d->getTexte()<<endl<<"Entree : ";
            cin>>pTexte;
            if(pTexte=="Aida"){cout<<""<<endl;
            }else
            Jeu.getGraphe().parcoursGraphe(d->rep(pTexte));
        }else
        if (noeud->getDelim()=='c')
        {
            c=(Combat*) noeud;
            Jeu.getGraphe().parcoursGraphe(0);
        }
        noeud=Jeu.getCNoeud();
    
    
    //cout<<"un indice "<<.rep()<<endl;
    
    /*cout<<d->getTexte()<<endl<<"Entree : ";
    cin>>pTexte;
    Jeu.getGraphe().parcoursGraphe(d->rep(pTexte));

    noeud=Jeu.getCNoeud();
    d = (Dialogue*) noeud;
    cout<<"un indice "<<noeud->getID()<<endl;

    cout<<d->getTexte()<<endl<<"Entree : ";
    
    cin>>pTexte;
    Jeu.getGraphe().parcoursGraphe(d->rep(pTexte));

    noeud=Jeu.getCNoeud();
    cout<<"un indice "<<noeud->getID()<<endl;
    cout<<Jeu.getGraphe().isFeuille(noeud);*/
    }
    d=(Dialogue*) noeud;
    cout<<d->getTexte()<<endl;
    return 0;
}





