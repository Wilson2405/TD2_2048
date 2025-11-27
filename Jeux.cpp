#include "Jeux.h"

Jeux::Jeux(Grille g)
: g_(g), score_(0)
{
    highscore_ = load_();
    if(highscore_ < 0)
        throw std::invalid_argument("Highscore must be positive");
}

int Jeux::load_() const
{
    std::ifstream file("highscore.txt");
    if (!file.is_open()) {
        // Si le fichier n’existe pas encore : highscore = 0
        return 0;
    }

    int highscore;
    file >> highscore;

    if (file.fail()) return 0; // Fichier vide ou mal formaté → 0

    return highscore;
}



std::string Jeux::menu_() const
{
    std::cout <<"Pour aller en bas, taper 2.        |\n"
              <<"Pour aller en haut, taper 8.       |Votre score: " << score_ <<"\n"
              <<"Pour aller a gauche, taper 4.      |Record: " << highscore_ << "\n"
              <<"Pour aller a droite, taper 6.      |\n"
              <<"Pour quitter, taper 5.\n";
    std::string choix = "";
    while(choix!="5" && choix!="2" && choix!="4" && choix!="6" && choix!="8"){
        std::cout << "Votre choix: ";
        std::cin >> choix;
    }
    return choix;
}

bool Jeux::newHighScore_() const
{
    return(score_ > highscore_);
}


void Jeux::save_() const
{
     std::ofstream file("highscore.txt", std::ios::trunc);

    if (!file.is_open()) {
        std::cout << "Impossible d’ouvrir highscore.txt !" << std::endl;
        return;
    }

    file << highscore_;
}

void Jeux::start()
{
    std::cout << "Bienvenue dans le jeux du 2048. Voici la grille de jeux:\n";
    g_.ajoutTuile();
    g_.ajoutTuile();
    std::string q = "";
    while(!g_.estRemplie() && !g_.estFinie() && q != "5"){
        std::cout << to_string(g_) << std::endl;
        q = menu_();
        g_.decalage(q, score_);
        g_.ajoutTuile();
    }
    if(q == "5")
    std::cout << "Vous avez décidé de quitter la partie." << std::endl;
    if(g_.estRemplie())
    std::cout << "GAME OVER: La grille est remplie!" << std::endl;
    if(g_.estFinie())
    std::cout << "Félicitation !! Vous avez terminé la grille " 
            << g_.taille() <<" x " << g_.taille() <<".\n";
    if(newHighScore_()){
        std::cout << "Nouveau record : " << score_ << std::endl;
        highscore_ = score_;
        save_();
    }
}