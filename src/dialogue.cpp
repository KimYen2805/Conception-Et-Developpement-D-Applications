#include "dialogue.h"


Dialogue::Dialogue(int ind, string nom, string txt, string rep[MAXREP], int nb){
    id=ind;
    nomNoeud=nom;
    texte=txt;
    for (int i=0;i<nb;i++){
        reponse.push_back(rep[i]);
    }
}

