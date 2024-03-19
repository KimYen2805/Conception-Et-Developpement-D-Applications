#include "combat.h"


Combat::Combat(){
    indice=1;
    
}
Combat::Combat(Ennemi eg[MAXENNEMI], int gs, int ind){
    indice=ind;
    for (int i=0;i<gs;i++)
        {
            ennGroup[i]=eg[i];
        }
}

Combat::~Combat(){

}

int Combat::castSort(){
    string s;
    cout<<"Entrer un sort : ";
    cin >> s;
    int sort = joueur.isSort(s);
    if(sort<0){
        cout<<"Sort invalide"<<endl;
    }
    
    joueur.getSort(sort).affSort();
    return sort;
}

void Combat::ennHitPlay(Sort sort){

}

void Combat::playHitEnn(Sort sort){
    

}

void Combat::ennTurn(){

}
void Combat::playTurn(){

}

void Combat::fight(){

}
