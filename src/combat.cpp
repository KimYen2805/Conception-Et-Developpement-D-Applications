#include "combat.h"


Combat::Combat(){
    id=1;
    
}
Combat::Combat(Ennemi eg[MAXENNEMI], int gs, int ind, string nomN,char d){
    id=ind;
    nomNoeud=nomN;
    delim=d;
    for (int i=0;i<gs;i++)
        {
            ennGroup.push_back(eg[i]);
        }
}

Combat::~Combat(){

}

int Combat::castSort(Joueur& j, string s){
    int sort = j.isSort(s);
    if(sort<0){
        cout<<"Sort invalide"<<endl;
    }else{  
        j.getSort(sort).affSort();
    }
    return sort;
}

void Combat::ennHitPlay(Joueur& j, Sort sort){

}

void Combat::playHitEnn(Joueur& j, float sort){

    ennGroup[rand()%(ennGroup.size())].updatePVEnn(-sort);
    cout<< ennGroup[0].getPointDeVieEnnemi()<<endl;
}

void Combat::ennTurn(){

}

void Combat::playTurn(Joueur& j, int sort){
    Sort s = j.getSort(sort);
    if(s.getEffetSort().getNomEffet()=="degatVie")
    {
        cout<<"here"<<endl;
        playHitEnn(j, j.getPVJoueur()*s.getEffetSort().getPuissanceEffet());
        j.updatePVJoueur(-j.getPVJoueur()*s.getCout());
    }
    if(j.getSort(sort).getCout()<=j.getMana())
    {
        
    }
}

int Combat::isFight(Joueur& j){
    cout<<"Points de vie du joueur: "<<j.getPVJoueur()<<endl;
    if (j.getPVJoueur()<=0)
    {
        return 1;//si le joueur perds avance au noeud de défaite
    }
    else
    {
        for(long unsigned int i=0;i<ennGroup.size();i++)
        {
            cout<<"Points de vie de l'ennemi "<<i+1<<": "<<ennGroup[i].getPointDeVieEnnemi()<<endl;
            if(ennGroup[i].getPointDeVieEnnemi()<=0)
            {
                return 0;//si les ennemi perdent, avance au neoud de victoire
            }
        }
    }
    return -1;//le combat n'est pas terminé
}
