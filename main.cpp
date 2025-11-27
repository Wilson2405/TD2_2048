#include"Grille.h"
#include"Affichage.h"
#include "Randint.h"
#include<iostream>

int main(){
    std::srand(std::time(nullptr));  // initialise la graine aléatoire
    Grille g1;
    g1.ajoutTuile();
    std::string q = " ";
    while(!g1.estRemplie() && !g1.estFinie() && q != "5"){
        std::cout << to_string(g1) << std::endl;
        std::cout << "Votre choix : ";
        std::cin >> q;
        g1.decalage(q);
        g1.ajoutTuile();
    }
    return 0;
}