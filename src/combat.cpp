#include "combat.h"


Combat::Combat(){
    id=1;
    
}
Combat::Combat(Ennemi eg[MAXENNEMI], int gs, int ind){
    id=ind;
    for (int i=0;i<gs;i++)
        {
            ennGroup[i]=eg[i];
        }
}

Combat::~Combat(){

}

int Combat::castSort(Joueur& j){
    string s;
    cout<<"Entrer un sort : ";
    cin >> s;
    int sort = j.isSort(s);
    if(sort<0){
        cout<<"Sort invalide"<<endl;
    }
    
    j.getSort(sort).affSort();
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

void Combat::fight(Joueur& j){

}
