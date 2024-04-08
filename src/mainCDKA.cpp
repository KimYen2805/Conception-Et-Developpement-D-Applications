#include "jeu.h"
#include <iostream>
using namespace std;

int main()
{
    Jeu Jeu;

    Noeud* noeud;
    noeud=Jeu.getCNoeud();

    string pTexte; //Les futurs réponses du joueur dans le main;
    Dialogue* d;
    Combat* c;
    cout<<endl<<endl;
    while(!Jeu.getGraphe().isFeuille(noeud))
    {
        if (noeud->getDelim()=='d')
        {
            int isValid=-1;
            while(isValid==-1)
            {
                d=(Dialogue*) noeud;
                cout<<d->getTexte()<<endl<<"Choix : ";
                cin>>pTexte;
                if(pTexte=="Aide")
                {
                    cout<<d->getRep()<<endl;
                }else
                {isValid =d->rep(pTexte);
                if (isValid!=-1){Jeu.getGraphe().parcoursGraphe(isValid);}
                else{cout<<"Reponse invalide au dialogue"<<endl;}}
                
            }
        }else
        if (noeud->getDelim()=='c')
        {
            cout<<"Dans le combat"<<endl;
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
    cout<<d->getTexte()<<endl;//Dialogue de fin
    return 0;
}





