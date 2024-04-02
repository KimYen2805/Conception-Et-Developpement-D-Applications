#include "dialogue.h"


Dialogue::Dialogue(int ind, string nom, string txt, string rep[MAXREP], int nb, char d){
    id=ind;
    nomNoeud=nom;
    texte=txt;
    delim=d;
    for (int i=0;i<nb;i++){
        reponse.push_back(rep[i]);
    }
}

int Dialogue::rep(string word)
{
    for(int i=0;i<reponse.size();i++)
    {
        if(word==reponse[i])
        {
            return i;
        }
    }return -1;
}

