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

void Combat::ennHitPlay(Joueur& j, float sort){
    j.updatePVJoueur(-sort);
}

void Combat::playHitEnn(Joueur& j, float degat, int tar){
    if (tar==0)
    { 
        int val=rand()%(ennGroup.size());
        while (ennGroup[val].getPointDeVieEnnemi()<0)
        {
            val=rand()%(ennGroup.size());
        }
        ennGroup[val].updatePVEnn(-degat);
    }
    else ennGroup[tar-1].updatePVEnn(-degat);
}

void Combat::ennTurn(Joueur& j){
    for (long unsigned int i = 0; i<ennGroup.size(); i++)
    {
        
        Ennemi e=ennGroup[i];
        if (e.getPointDeVieEnnemi()>0)
        {

            Sort s =j.getSort(e.getSort(rand() % e.getSsize()));

            s.affSort();
            if(s.getEffetSort().getNomEffet()=="degatVie")
            {
                ennHitPlay(j, e.getPointDeVieEnnemi() * s.getEffetSort().getPuissanceEffet() * e.getPuissanceEnnemi()/100);
                ennGroup[i].updatePVEnn( -float(e.getPointDeVieEnnemi() * s.getCout() * e.getPuissanceEnnemi())/100.0);
            }else
            if(s.getEffetSort().getNomEffet()=="degatMana")
            {
                ennHitPlay(j, s.getEffetSort().getPuissanceEffet() * e.getPuissanceEnnemi() /100);              
            }else
            if(s.getEffetSort().getNomEffet()=="soinMana")
            {
                ennGroup[rand() % ennGroup.size()].updatePVEnn( s.getEffetSort().getPuissanceEffet() * e.getPuissanceEnnemi() /100 );
            }
        }
    }
}

void Combat::playTurn(Joueur& j, int sort, int tar){
    Sort s = j.getSort(sort);
    if(s.getEffetSort().getNomEffet()=="degatVie")
    {
        cout<<endl;
        playHitEnn(j, j.getPVJoueur()*s.getEffetSort().getPuissanceEffet(), 0);
        j.updatePVJoueur(-j.getPVJoueur()*s.getCout());
    }else

    if(j.getSort(sort).getCout()<=j.getMana() && s.getEffetSort().getNomEffet()=="degatMana")
    {
        cout<<endl;
        playHitEnn(j, s.getEffetSort().getPuissanceEffet(), tar);
        j.updateMana(-s.getCout());
    }else
    if(j.getSort(sort).getCout()<=j.getMana() && s.getEffetSort().getNomEffet()=="soinMana")
    {
        cout<<endl;
        j.updatePVJoueur(s.getEffetSort().getPuissanceEffet());
        j.updateMana(-s.getCout());
    }

}

int Combat::isFight(Joueur& j) const{
    if (j.getPVJoueur()<=0) return 1;//si le joueur perds avance au noeud de défaite        
    else{
        for(long unsigned int i=0;i<ennGroup.size();i++)
        {
            if(ennGroup[i].getPointDeVieEnnemi()>0) return -1;//Un ennemi vie encore, le combat n'est pas terminé
        }
        return 0;//si les ennemi perdent, avance au neoud de victoire
    } 
}

void Combat::affStat(Joueur& j) const{
    cout<<"Points de vie du joueur: "<<j.getPVJoueur()<<endl;
    cout<<"Mana du joueur: "<<j.getMana()<<endl<<endl;
    for(long unsigned int i=0;i<ennGroup.size();i++)
    {
        cout<<"Points de vie de l'ennemi "<<i+1<<": "<<ennGroup[i].getPointDeVieEnnemi()<<endl;
    }

}
