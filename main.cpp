#include"Grille.h"
#include"Affichage.h"
#include "Randint.h"
#include"Jeux.h"

int main(){
    std::srand(std::time(nullptr));  // initialise la graine aléatoire
    Grille g1(5);
    Jeux game(g1);
    game.start();
    std::string answer = "y";
    while(answer != "n" && answer != "N" && answer != "no" && answer != "" ){
        std::cout << "Nouvelle partie?[y/n] ";
        std::cin >> answer;
        if(answer == "y" || answer == "yes" || answer == "Y")
            game.restart();
    }
    return 0;
}