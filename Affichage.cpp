#include"Affichage.h"

std::string to_string(const Tuile& t)
{// setw force à afficher les espaces dans le to_string
    std::ostringstream oss;
    oss << "|";
    int v = t.val();
    if(v !=0){
        if(v<10) oss<<std::setw(2)<< " "<<v<<std::setw(2)<< " ";
        else if (v<100) oss<<std::setw(2)<< " "<<v<<std::setw(1)<< " ";
        else if (v<1000) oss<<std::setw(1)<< " "<<v<<std::setw(1)<< " ";
        else oss<<std::setw(1)<< " "<<v;
    }
    else oss <<std::setw(5)<< " ";
    return oss.str();
}

std::string to_string(const  Grille& g)
{
    std::string m="";
    int n = g.taille();
    for(int i = 0; i < n; i++ ){
        for(int k = 0; k < n; k++){
            m+="+-----";
        }
        m+="+\n";
        for(int j = 0; j < n; j++){
            m+=to_string(g.tuile(i, j));
        }
        m+="|\n";
    }
    for(int k = 0; k < n; k++){
        m+="+-----";
    }
    m+="+\n";
    return m;


}