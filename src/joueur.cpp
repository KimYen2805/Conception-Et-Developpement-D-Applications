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
    for(int i=0; i<=NBSORT;i++)
    {
        tabSort[i] = inSort[i]; 
    }

}

Joueur::Joueur(const string &filename)  {
    ifstream fichier(filename.c_str());
    if(!fichier.is_open()){ cout<<"file not open"<<endl;
    }else{cout<<"fileOpen"<<endl;
    string nom, sort, effet;
    int pvMx, mnMx;
    float coutS, puissanceEffet;
    Sort inSort[NBSORT];
    
    fichier >> nom >> pvMx >> mnMx ;
    cout<<nom<<" "<<pvMx<<" "<<mnMx<<endl;
    nomJoueur=nom;
    pointDeVieMax=pointsDeVie = pvMx;
    maxMana=mana = mnMx;

    for (int i = 0; i < NBSORT; ++i)
    {
            fichier >> sort >> coutS >> effet >> puissanceEffet; 
            
            inSort[i].setNomSort(sort) ;
            inSort[i].setCout(coutS) ;
            inSort[i].getEffetSort().setNomEffet(effet) ;
            inSort[i].getEffetSort().setPuissanceEffet(puissanceEffet) ;
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

void Joueur::testRegression() {
    cout << "Exécution du test de régression pour la classe Joueur..." << endl;

    // Test 1: Vérifiez si les points de vie initiaux sont égaux à pointDeVieMax
    if (getPVJoueur() == pointDeVieMax) {
        cout << "Test 1 réussi : Les points de vie initiaux sont égaux à pointDeVieMax." << endl;
    } else {
        cout << "Test 1 échoué : Les points de vie initiaux ne sont pas égaux à pointDeVieMax." << endl;
    }

    // Test 2: Vérifiez si le mana initial est égal à maxMana
    if (getMana() == maxMana) {
        cout << "Test 2 réussi : Le mana initial est égal à maxMana." << endl;
    } else {
        cout << "Test 2 échoué : Le mana initial n'est pas égal à maxMana." << endl;
    }

    cout << "Test de régression terminé." << endl;
}