#ifndef _JOUEUR_H
#define _JOUEUR_H
#include "sort.h"
#include "objet.h"
using namespace std;

const int NBSORT=4;
const int NBOBJ=50;


class Joueur{
private :
   

    string nomJoueur;       // Nom du joueur

    int pointDeVieMax;
    int pointsDeVie;        // Points de vie du joueur actuelle

    int maxMana;
    int mana;

    Sort tabSort[NBSORT];          // Tableau de sorts 
    Objet tabObjet[NBOBJ];

public :
    //Contructeur
    Joueur();
    Joueur(string nom, int pvMx, int mnMx, Sort inSort[NBSORT]);
    Joueur(const string &filename);
    //Decontructeur
    ~Joueur();
    string getNomJoueur() const ;
    void setNomJoueur(string nom);

    int getPVJoueur() ;
    int getPVMAXJoueur() ;

    void setPVMAXJoueur(int pv);
    void setPVJoueur(int pv);

    void updatePVJoueur(int pv);

    int getMana();
    int getMAXMana();

    void setMana(int ma);
    void setMAXMana(int ma);

    void updateMana(int ma);

    /**
    *@brief renvoie l'indice d'un sort si le nom est valide, -1 sinon
    *@param so nom d'un sort potentiel 
    *@return un entier entre -1 et NBSORT-1
    */
    int isSort(string so);

    /**
    *@brief renvoie un sort s
    *@param i indice d'un sort
    *@return un sort
    */
    Sort getSort(int i);
    
    //test
    void testRegression();
    
};
#endif




