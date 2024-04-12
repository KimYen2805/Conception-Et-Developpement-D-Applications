#include "jeu.h"
#include <iostream>
using namespace std;

int main()
{
    Jeu Jeu;
    Joueur joueur=Jeu.getJoueur();
    Noeud* noeud;
    noeud=Jeu.getCNoeud();

    string pTexte; //Les futurs réponses du joueur dans le main;
    Dialogue* d;
    Combat* c;

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
            while(c->isFight(joueur)==-1)
            {
                cout<<"Action joueur: ";
                cin>>pTexte;
                int iSort = c->castSort(joueur, pTexte);
                if (iSort!=-1)
                {
                    c->playTurn(joueur,iSort);
                }
                if(c->isFight(joueur)==-1)
                {
                    c->ennTurn();
                }
                
            }
            Jeu.getGraphe().parcoursGraphe(c->isFight(joueur));
        }

        noeud=Jeu.getCNoeud(); //avancer dans le jeu en fonction des résultats
    }
    d=(Dialogue*) noeud;
    cout<<d->getTexte()<<endl;//Dialogue de fin
    return 0;
}










