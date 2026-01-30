#include"Grille.h"
#include"Randint.h"
#include"Jeux.h"

int main(){
    std::srand(std::time(nullptr));
    Grille g1(5);
    Jeux game(g1);
    game.start();
    std::string answer = "y";
    while(answer == "y" ||answer == "Y" || answer == "yes"){
        std::cout << "Nouvelle partie?[y/N] ";
        std::cin >> answer;
        if(answer == "y" || answer == "yes" || answer == "Y")
            game.restart();
    }
    
    return 0;
}