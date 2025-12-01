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



std::string Jeux::menu_(int deplacement) const
{
    std::cout <<"Pour aller en bas, taper 2.        |\n"
              <<"Pour aller en haut, taper 8.       |Votre score: " << score_ <<"\n"
              <<"Pour aller a gauche, taper 4.      |Record: " << highscore_ << "\n"
              <<"Pour aller a droite, taper 6.      |Deplacements: " << deplacement << "\n"
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

bool Jeux::GameOver_() const
{
    if(g_.isFull()){
        if(!g_.canFusion()) return true;
    }
    return false;
}

void Jeux::start()
{
    std::cout << "Bienvenue dans le jeux du 2048. Voici la grille de jeux:\n";
    g_.addTuile();
    g_.addTuile();
    std::string q = "";
    int nb_deplacement=0;
    while(!GameOver_() && !g_.isFinish() && q != "5"){
        std::cout << to_string(g_) << std::endl;
        q = menu_(nb_deplacement);
        g_.move(q, score_);
        g_.addTuile();
        nb_deplacement++;
    }
    if(q == "5")
    std::cout << "Vous avez décidé de quitter la partie." << std::endl;
    if(GameOver_())
    std::cout << "GAME OVER: La grille est remplie!" << std::endl;
    if(g_.isFinish())
    std::cout << to_string(g_) << "\nFélicitation !! Vous avez terminé la grille " 
            << g_.taille() <<" x " << g_.taille() <<".\n";
    if(newHighScore_()){
        std::cout << "Nouveau record : " << score_ << std::endl;
        highscore_ = score_;
        save_();
    }
}

void Jeux::restart()
{
    g_.clear();
    score_=0;
    start();
}