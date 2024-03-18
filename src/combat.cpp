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
    Ennemi ennGroup[0]= Ennemi();
}
/*
Combat::~Combat(){

}

void Combat::castSort(){

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