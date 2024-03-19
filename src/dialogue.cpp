#include "dialogue.h"


Dialogue::Dialogue(int ind, string nom, string txt, string rep[MAXREP], int* f, int nb){
    indice=ind;
    nomNoeud=nom;
    texte=txt;
    fils = new int[nb+1];
    for (int i = 0; i<=nb;i++)
    {
        reponse[i]=rep[i];
        fils[i]=f[i];
    }
    
}

