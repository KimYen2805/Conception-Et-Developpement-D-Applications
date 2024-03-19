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
    cin >> s;
    int sort = joueur.isSort(s);
    if(sort<0){
        std::cout<<"Sort invalide"<<endl;
    }
    std::cout<<"Sort invalide"<<endl;
    joueur.getSort(sort).affSort();
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
