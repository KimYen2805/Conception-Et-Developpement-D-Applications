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
/*
Combat::~Combat(){

}

void Combat::castSort(){
    
    float joueur.getSort(sort)
    if()
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
*/