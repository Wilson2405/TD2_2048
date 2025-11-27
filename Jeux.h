#ifndef JEUX_H
#define JEUX_H
#include "Grille.h"
#include "Affichage.h"
#include <iostream>
#include<stdexcept>


class Jeux
{
    private:
        Grille g_;
        int highscore_;
        int score_;
        bool newHighScore_() const;
        std::string menu_() const;
    public:
        Jeux(Grille g, int highscore = 0);
        
        void start();
        



};



#endif