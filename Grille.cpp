#include"Grille.h"

Tuile::Tuile(int val): val_(val)
{
    if(!isValid())
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

void Tuile::clear()
{
    val_ = 0;
}

bool Tuile::isEmpty()
{
    if(val_ == 0)
        return true;
    else
        return false;
}

bool Tuile::isValid()
{
    if(isEmpty()) return true;
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

Grille::Grille(int n) : size_(n), matrice_(size_, std::vector<Tuile>(size_))
{
    if(size_ <= 3) {
        throw std::invalid_argument("The grid size is too small!");
    }
}

int Grille::size() const
{
    return size_;
}

const Tuile& Grille::tuile(int i, int j) const
{
    return matrice_[i][j];
}

void Grille::addTuile(){
    int x = randint(0, size_-1);
    int y = randint(0, size_-1);
    while(!matrice_[x][y].isEmpty()){
        x = randint(0, size_-1);
        y = randint(0, size_-1);
    }
    matrice_[x][y].update();
}

void Grille::moveLeft_(int& score){
    int i, j, x;
    Tuile v;
    for (i = 0; i < size_; i++) {
        x = 0;
        for (j = 0; j < size_; j++) {
            v = matrice_[i][j];
            if (!v.isEmpty()) {
                matrice_[i][j].clear();
                matrice_[i][x] = v;
                if (x != 0) {
                    if (v == matrice_[i][x - 1]) {
                        score++;
                        matrice_[i][x].clear();
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

void Grille::moveRight_(int& score){
    int i, j, x;
    Tuile v;
    for(i = 0; i < size_; i++){
        x = size_-1;
        for(j = size_-1; j >= 0; j--){
            v = matrice_[i][j];
            if (!v.isEmpty()) {
                matrice_[i][j].clear();
                matrice_[i][x] = v;
                if (x != size_-1) {
                    if (v == matrice_[i][x + 1]) {
                        score++;
                        matrice_[i][x].clear();
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

void Grille::moveDown_(int& score) {
    int i, j, x;
    Tuile v;
    for(j = 0; j < size_; j++){
        x = size_-1;
        for(i = size_-1; i >= 0; i--){
            v = matrice_[i][j];
            if (!v.isEmpty()) {
                matrice_[i][j].clear();
                matrice_[x][j] = v;
                if(x != size_-1){
                    if(v == matrice_[x + 1][j]){
                        score++;
                        matrice_[x][j].clear();
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

void Grille::moveUp_(int& score){
    int i, j, x;
    Tuile v;
    for(j = 0; j < size_; j++){
        x = 0;
        for(i = 0; i < size_; i++){
            v = matrice_[i][j];
            if(!v.isEmpty()){
                matrice_[i][j].clear();
                matrice_[x][j] = v;
                if(x != 0){
                    if(v == matrice_[x - 1][j]){
                        score++;
                        matrice_[x][j].clear();
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

void Grille::move(std::string n, int& score)
{
    if(n == "2") moveDown_(score);
    if(n == "4") moveLeft_(score);
    if(n == "6") moveRight_(score);
    if(n == "8") moveUp_(score);
}

bool Grille::isFull() const
{
    int nbremplie=0;
    for(int i = 0; i < size_; i++){
        for(int j = 0; j< size_; j++){
            Tuile v = matrice_[i][j];
            if(!v.isEmpty()) nbremplie++;
        }
    }
    if(nbremplie == size_*size_) return true;
    else return false;
}

bool Grille::isFinish() const 
{
    for(int i = 0; i < size_; i++){
        for(int j = 0; j< size_; j++){
            Tuile v = matrice_[i][j];
            if(v.val() == 2048) return true;
        }
    }
    return false;
}

void Grille::clear()
{
    for(int i=0; i<size_; i++){
        for(int j=0; j<size_; j++){
            matrice_[i][j].clear();
        }
    }
}

bool Grille::canFusion() const {
    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < size_; j++) {
            // Comparer avec la tuile à droite
            if (j + 1 < size_) {
                if (matrice_[i][j] == matrice_[i][j + 1])
                    return true;
            }
            // Comparer avec la tuile en bas
            if (i + 1 < size_) {
                if (matrice_[i][j] == matrice_[i + 1][j])
                    return true;
            }
        }
    }
    return false;
}