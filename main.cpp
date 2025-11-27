#include"Grille.h"
#include"Affichage.h"
#include "Randint.h"
#include"Jeux.h"

int main(){
    std::srand(std::time(nullptr));  // initialise la graine aléatoire
    Grille g1(5);
    Jeux game(g1);
    game.start();
    
    return 0;
}