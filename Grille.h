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
        void clear();
        bool isEmpty();
        bool isValid();
        bool operator==(const Tuile& other) const;
};

class Grille
{
    private:
        int size_;
        std::vector<std::vector<Tuile>> matrice_;
        void moveRight_(int& score);
        void moveLeft_(int& score);
        void moveUp_(int& score);
        void moveDown_(int& score);

    public:
        Grille(int n=4);
        int size() const;
        const Tuile& tuile(int i, int j) const;
        void addTuile();
        void move(std::string n, int& score);
        bool isFull() const;
        bool canFusion() const;
        bool isFinish() const;
        void clear();
};

#endif // GRILLE_H

