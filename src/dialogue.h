#ifndef _DIALOGUE_H
#define _DIALOGUE_H
#include <string>
#include "noeud.h"
const int MAXREP= 5;

using namespace std; 
class Dialogue : public Noeud{
 private: 
    string texte; 
    string reponse[MAXREP]; 
public:
/**
 * @brief initialise un noeud dialogue avec les paramètres
 * @param ind indice du noeud
 * @param nom nom du noeud
 * @param txt le texte du dialogue
 * @param rep tableau des réponses
 * @param fils pointeur vers les fils
 * @param nombre de fils et réponses
*/
    Dialogue(int ind, string nom, string txt, string rep[MAXREP], int* f, int nb);

};
#endif