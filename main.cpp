#include"Grille.h"
#include"Randint.h"
#include"Jeux.h"

int main(){
    try 
    {
        std::srand(std::time(nullptr));
        int size = 5;
        Grille g1(size);
        Jeux game(g1);
        game.start();
        std::string answer = "y";
        while(answer == "y" ||answer == "Y" || answer == "yes"){
            std::cout << "Nouvelle partie?[y/N] ";
            std::cin >> answer;
            if(answer == "y" || answer == "yes" || answer == "Y")
                game.restart();
        }
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << "Error : " << e.what() << std::endl;
    }
    return 0;
}