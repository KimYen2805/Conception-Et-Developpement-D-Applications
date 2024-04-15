#ifndef _SORT_H
#define _SORT_H
#include "effet.h"
#include <string>
#include <sstream>
using namespace std;

class Sort
{

private:
    string nomSort;
    float coutS;
    Effet effetSort;

public:
    Sort();
    /**
     * @brief change le nom du sort
     * @param nvnomSort
    */
    void setNomSort(string nvnomSort);
    /**
     * @brief change le cout du sort
     * @param nvCout
    */
    void setCout(float nvCout);
    /**
     * @brief change l'effet du sort
     * @param nvEffetSort
    */
    void setEffetSort(Effet nvEffetSort);
    /**
     * @return nom
    */
    string getNomSort() const;
    /**
     * @return cout
    */
    float getCout() const;
    /**
     * @return effet
    */
    Effet getEffetSort() const;
    /**
     * @brief affiche les paramètre du sort
    */
    void affSort();
    /**
     * @brief identique, pour sdl
     * @param ss string de passage
    */
    void affSortSDL(std::stringstream& ss);
};
#endif