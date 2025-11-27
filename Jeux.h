#ifndef JEUX_H
#define JEUX_H
#include"Grille.h"
#include"Affichage.h"
#include<iostream>
#include<stdexcept>
#include<fstream>


class Jeux
{
    private:
        Grille g_;
        int highscore_;
        int score_;
        bool newHighScore_() const;
        std::string menu_() const;
        int load_() const;
        void save_() const;
    public:
        Jeux(Grille g);
        
        void start();
        



};



#endif