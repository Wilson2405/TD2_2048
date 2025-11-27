#ifndef GRILLE_H
#define GRILLE_H

#include"Randint.h"
#include<string>
#include<vector>
#include<stdexcept>

class Tuile 
{
    private:
        int val_;
    public:
        Tuile(int val=0);
        int val() const;
        void update();
        void vider();
        bool estVide();
        bool estValide();
        bool operator==(const Tuile& other) const;
};

class Grille
{
    private:
        int taille_;
        std::vector<std::vector<Tuile>> matrice_;
        void decalageDroite_(int& score);
        void decalageGauche_(int& score);
        void decalageHaut_(int& score);
        void decalageBas_(int& score);

    public:
        Grille(int n=4);
        int taille() const;
        const Tuile& tuile(int i, int j) const;
        void ajoutTuile();
        void decalage(std::string n, int& score);
        bool estRemplie() const;
        bool estFinie() const;
};

#endif // GRILLE_H

