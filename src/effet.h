#ifndef _EFFET_H
#define _EFFET_H

#include <string>
using namespace std;

class Effet
{

private:
    string nomEffet;     //Nom de l'effet
    float puissanceEffet; 

public:
    Effet();

    void setNomEffet(string nvNom);
    void setPuissanceEffet(float nvPuissance);

    string getNomEffet() const; 
    float getPuissanceEffet() const; 
};

#endif