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

void Combat::ennHitPlay(Sort sort){

}

void Combat::playHitEnn(Sort sort){
    

}

void Combat::ennTurn(){

}
void Combat::playTurn(Joueur& j, int sort){
    Sort s = j.getSort(sort);
    if(s.getEffetSort().getNomEffet()=="degatVie")
    {
        j.setPVJoueur(j.getPVJoueur()*s.getCout());
        playHitEnn(s);
    }
    if(j.getSort(sort).getCout()<=j.getMana())
    {
        
    }
}

int Combat::isFight(Joueur& j){
    cout<<j.getPVJoueur()<<endl;
    if (j.getPVJoueur()<=0)
    {
        return 1;//si le joueur perds avance au noeud de défaite
    }
    else
    {
        for(long unsigned int i=0;i<ennGroup.size();i++)
        {
            if(ennGroup[i].getPointDeVieEnnemi()<=0)
            {
                return 0;//si les ennemi perdent, avance au neoud de victoire
            }
        }
    }
    return -1;//le combat n'est pas terminé
}
