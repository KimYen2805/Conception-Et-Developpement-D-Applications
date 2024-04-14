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
    /**
     * @brief Set the Nom Effet object
     * 
     * @param nvNom 
     */
    void setNomEffet(string nvNom);
    /**
     * @brief Set the Puissance Effet object
     * 
     * @param nvPuissance 
     */
    void setPuissanceEffet(float nvPuissance);
    /**
     * @brief Get the Nom Effet object
     * 
     * @return string 
     */
    string getNomEffet() const; 
    /**
     * @brief Get the Puissance Effet object
     * 
     * @return float 
     */
    float getPuissanceEffet() const; 

};

#endif