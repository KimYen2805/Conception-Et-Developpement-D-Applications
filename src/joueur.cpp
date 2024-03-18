#include <iostream>
#include <fstream>
#include "joueur.h"
using namespace std; 


Joueur::Joueur()  {

    nomJoueur = "";
    pointDeVieMax = 0;
    pointsDeVie = pointDeVieMax;
    maxMana = 0;
    mana = maxMana;  
}

Joueur::Joueur(string nom, int pvMx, int mnMx, Sort inSort[NBSORT])  {

    nomJoueur = nom;
    pointDeVieMax = pvMx;
    pointsDeVie = pointDeVieMax;
    maxMana = mnMx;
    mana = maxMana;
    for(int i=0; i<NBSORT;i++)
    {
        tabSort[i] = inSort[i]; 
    }

}

Joueur::Joueur(const string &filename)  {
    ifstream fichier(filename.c_str());
    if(!fichier.is_open()){ cout<<"file not open"<<endl;
    }else{cout<<"fileOpen"<<endl;
    string nom, sort, neffet;
    int pvMx, mnMx;
    float coutS, puissanceEffet;
    Effet effet;
   
    
    fichier >> nom >> pvMx >> mnMx  ;
    cout<<nom<<" "<<pvMx<<" "<<mnMx<<endl;
    nomJoueur=nom;
    pointDeVieMax=pointsDeVie = pvMx;
    maxMana=mana = mnMx;

    for (int i = 0; i < NBSORT; ++i)
    {
            fichier >> sort >> coutS >> neffet >> puissanceEffet ; 
            cout<<sort<<" "<<coutS<<" "<<neffet<<endl;
            tabSort[i].setNomSort(sort) ;
            tabSort[i].setCout(coutS) ;
            effet.setNomEffet(neffet);
            effet.setPuissanceEffet(puissanceEffet);
            tabSort[i].setEffetSort(effet) ;
            
    }
    
    fichier.close();
    cout << "Lecture du joueur " << filename << " ... OK\n";
    }
}

Joueur :: ~Joueur() {
    //delete[] tabSort;
    //delete[] tabObjet;
}


string Joueur ::getNomJoueur()const {
    return nomJoueur; 
}
void Joueur::setNomJoueur(string nom){
    nomJoueur=nom;
}

int Joueur ::getPVJoueur() {
    return pointsDeVie;
}
int Joueur::getPVMAXJoueur(){
    return pointDeVieMax;
}
void Joueur::setPVMAXJoueur(int pv){
    pointDeVieMax=pv;
    pointsDeVie= pv; 
}

void Joueur::setPVJoueur(int pv) {
    pointsDeVie= pv; 
}
void Joueur::updatePVJoueur(int pv){
    if ((pointsDeVie + pv) >= pointDeVieMax)
    {
        pointsDeVie = pointDeVieMax;
    }else if((pointsDeVie + pv) <= 0)
    {
        pointsDeVie = 0;
    }else pointsDeVie += pv;
}

int Joueur ::getMana() {
    return mana;
}
int Joueur::getMAXMana(){
    return maxMana;
}
void Joueur::setMAXMana(int ma){
    maxMana=ma;
    mana= ma ;
}
void Joueur::setMana(int ma) {
    mana= ma ;
}
void Joueur::updateMana(int ma){
    if ((mana + ma) >= maxMana)
    {
        mana = maxMana;
    }else if((mana + ma) <= 0)
    {
        mana = 0;
    }else mana += ma;
}

int Joueur::getSort(string so){
    for (int i=0;i<NBSORT;i++)
    {
        if(so==tabSort[i].getNomSort() )
        {
            return i;
        }
    }
    return -1;
}
void Joueur::testRegression() {
    std::cout<<endl << "Execution du test de regression pour la classe Joueur..." << endl;

    // Test 1: Vérifiez si les points de vie initiaux sont égaux à pointDeVieMax
    if (getPVJoueur() == pointDeVieMax) {
        std::cout << "Test 1 reussi : Les points de vie initiaux sont egaux a pointDeVieMax." << endl;
    } else {
        std::cout << "Test 1 echoue : Les points de vie initiaux ne sont pas egaux a pointDeVieMax." << endl;
    }

    // Test 2: Vérifiez si le mana initial est égal à maxMana
    if (getMana() == maxMana) {
        std::cout << "Test 2 reussi : Le mana initial est egal a maxMana." << endl;
    } else {
        std::cout << "Test 2 echoue : Le mana initial n'est pas égal a maxMana." << endl;
    }
    cout<<nomJoueur<<" "<<pointDeVieMax<<endl;
    for (int i=0;i<NBSORT;i++)
    {
        std::cout <<"testReg :" <<tabSort[i].getNomSort() << " ";
        std::cout << tabSort[i].getCout() << " ";
        std::cout << tabSort[i].getEffetSort().getNomEffet() << " ";
        std::cout << tabSort[i].getEffetSort().getPuissanceEffet() << endl;
    }
    
    std::cout << "Test de regression termine." << endl;
}