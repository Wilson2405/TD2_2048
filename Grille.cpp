#include"Grille.h"

Tuile::Tuile(int val): val_(val)
{
    if(!estValide())
        throw std::invalid_argument("La tuile n'est pas valide");
}

int Tuile::val() const
{
    return val_;
}

void Tuile::update()
{
    if(val_ != 0)
        val_ = val_*2;
    else
        val_ = 2;
}

void Tuile::vider()
{
    val_ = 0;
}

bool Tuile::estVide()
{
    if(val_ == 0)
        return true;
    else
        return false;
}

bool Tuile::estValide()
{
    if(estVide()) return true;
    else{
        int test = val_;
        while(test%2 == 0){
            test = test/2;
        }
        if(test == 1) return true;
        else return false;
    }
}

bool Tuile::operator==(const Tuile& other) const
{
    return val_ == other.val_;
}

Grille::Grille(int n) : taille_(n), matrice_(taille_, std::vector<Tuile>(taille_))
{
    if(taille_ <= 3) {
        throw std::invalid_argument("La taille de la grille est trop petite!");
    }
}

int Grille::taille() const
{
    return taille_;
}

const Tuile& Grille::tuile(int i, int j) const
{
    return matrice_[i][j];
}

void Grille::ajoutTuile(){
    int x = randint(0, taille_-1);
    int y = randint(0, taille_-1);
    while(!matrice_[x][y].estVide()){
        x = randint(0, taille_-1);
        y = randint(0, taille_-1);
    }
    matrice_[x][y].update();
}

void Grille::decalageGauche_(int& score){
    int i, j, x;
    Tuile v;
    for (i = 0; i < taille_; i++) {
        x = 0;
        for (j = 0; j < taille_; j++) {
            v = matrice_[i][j];
            if (!v.estVide()) {
                matrice_[i][j].vider();
                matrice_[i][x] = v;
                if (x != 0) {
                    if (v == matrice_[i][x - 1]) {
                        score++;
                        matrice_[i][x].vider();
                        v.update();
                        matrice_[i][x - 1] = v;
                        x--;
                    }
                }
                x++;
            }
        }
    }
}

void Grille::decalageDroite_(int& score){
    int i, j, x;
    Tuile v;
    for(i = 0; i < taille_; i++){
        x = taille_-1;
        for(j = taille_-1; j >= 0; j--){
            v = matrice_[i][j];
            if (!v.estVide()) {
                matrice_[i][j].vider();
                matrice_[i][x] = v;
                if (x != taille_-1) {
                    if (v == matrice_[i][x + 1]) {
                        score++;
                        matrice_[i][x].vider();
                        v.update();
                        matrice_[i][x + 1] = v;
                        x++;
                    }
                }
                x--;
            }
        }
    }
}

void Grille::decalageBas_(int& score) {
    int i, j, x;
    Tuile v;
    for(j = 0; j < taille_; j++){
        x = taille_-1;
        for(i = taille_-1; i >= 0; i--){
            v = matrice_[i][j];
            if (!v.estVide()) {
                matrice_[i][j].vider();
                matrice_[x][j] = v;
                if(x != taille_-1){
                    if(v == matrice_[x + 1][j]){
                        score++;
                        matrice_[x][j].vider();
                        v.update();
                        matrice_[x + 1][j] = v;
                        x++;
                    }
                }
                x--;
            }
        }
    }
}

void Grille::decalageHaut_(int& score){
    int i, j, x;
    Tuile v;
    for(j = 0; j < taille_; j++){
        x = 0;
        for(i = 0; i < taille_; i++){
            v = matrice_[i][j];
            if(!v.estVide()){
                matrice_[i][j].vider();
                matrice_[x][j] = v;
                if(x != 0){
                    if(v == matrice_[x - 1][j]){
                        score++;
                        matrice_[x][j].vider();
                        v.update();
                        matrice_[x - 1][j] = v;
                        x--;
                    }
                }
                x++;
            }
        }
    }
}

void Grille::decalage(std::string n, int& score)
{
    if(n == "2") decalageBas_(score);
    if(n == "4") decalageGauche_(score);
    if(n == "6") decalageDroite_(score);
    if(n == "8") decalageHaut_(score);
}

bool Grille::estRemplie() const
{
    int nbremplie=0;
    for(int i = 0; i < taille_; i++){
        for(int j = 0; j< taille_; j++){
            Tuile v = matrice_[i][j];
            if(!v.estVide()) nbremplie++;
        }
    }
    if(nbremplie == taille_*taille_) return true;
    else return false;
}

bool Grille::estFinie() const 
{
    for(int i = 0; i < taille_; i++){
        for(int j = 0; j< taille_; j++){
            Tuile v = matrice_[i][j];
            if(v.val() == 2048) return true;
        }
    }
    return false;
}