#include "jeu.h"
#include <iostream>
using namespace std;

int main()
{
    /*string texte;
    getline(std::cin,texte);
    cout<<texte<<endl;*/
    Jeu Jeu;
    Graphe g = Jeu.getGraphe();
    //Combat combat;
    //Jeu.getJoueur().testRegression();
    Noeud* noeud;
    noeud=Jeu.getCNoeud();
    //cout<<"un indice "<<.rep()<<endl;
    string rep;
    cin>>rep;
    Jeu.getGraphe().parcoursGraphe(0);

    noeud=Jeu.getCNoeud();
    cout<<"un indice "<<noeud->getID()<<endl;

    Jeu.getGraphe().parcoursGraphe(1);

    noeud=Jeu.getCNoeud();
    cout<<"un indice "<<noeud->getID()<<endl;
    

    return 0;
}





