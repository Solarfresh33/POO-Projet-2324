#include "Jeu.hpp"

void Joueurs::afficher(){
    cout << "Nom : " << nom << endl;
    cout << "Vie : " << Vie << endl;
    cout << "Energie : " << Energie << endl;
    cout << "Attaque : " << Attaque << endl;
}

void Joueurs::attaquer(Joueurs &cible){
    cible.recevoirDegats(Attaque);
}

void Joueurs::recevoirDegats(int degats){
    Vie -= degats;
}

bool Joueurs::estVivant(){
    return Vie > 0;
}

Joueurs::Joueurs(){
    nom = "Inconnu";
    Vie = 0;
    Energie = 0;
    Attaque = 0;
}

Joueurs::Joueurs(string nom, int Vie, int Energie, int Attaque){
    this->nom = nom;
    this->Vie = Vie;
    this->Energie = Energie;
    this->Attaque = Attaque;
}

Joueurs::~Joueurs(){
    cout << "Destruction de " << nom << endl;
}

Heros::Heros(){
    nom = "Inconnu";
    Vie = 0;
    Energie = 0;
    Attaque = 0;
}

Heros::Heros(string nom, int Vie, int Energie, int Attaque){
    this->nom = nom;
    this->Vie = Vie;
    this->Energie = Energie;
    this->Attaque = Attaque;
}

Heros::~Heros(){
    cout << "Destruction de " << nom << endl;
}

void Heros::afficher(){
    cout << "Nom : " << nom << endl;
    cout << "Vie : " << Vie << endl;
    cout << "Energie : " << Energie << endl;
    cout << "Attaque : " << Attaque << endl;
}

void Heros::attaquer(Joueurs &cible){
    cible.recevoirDegats(Attaque);
}

void Heros::recevoirDegats(int degats){
    Vie -= degats;
}

bool Heros::estVivant(){
    return Vie > 0;
}

vilain::vilain(){
    nom = "Inconnu";
    Vie = 0;
    Energie = 0;
    Attaque = 0;
}



