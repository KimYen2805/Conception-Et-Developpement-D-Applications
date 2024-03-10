#ifndef _EFFET_H
#define _EFFET_H

#include <string>
using namespace std;

class Effet
{

private:
    string nomEffet;     //Nom de l'effet
    int puissanceEffet; 

public:
    Effet();
    void setPuissanceEffet(int nvPuissance);
    int getPuissanceEffet() const; 
};

#endif