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
    Dialogue();

};
#endif