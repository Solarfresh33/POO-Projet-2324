#include "Jeu.hpp"

void Joueurs::afficher(){
    cout << "Nom : " << nomJoueur << endl;
    cout << "Vie : " << VieJoueur << endl;
    cout << "Energie : " << EnergieJoueur << endl;
    cout << "Attaque : " << AttaqueJoueur << endl;
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
    nomJoueur = "Inconnu";
    VieJoueur = 0;
    EnergieJoueur = 0;
    AttaqueJoueur = 0;
}

Joueurs::Joueurs(string nom, int Vie, int Energie, int Attaque){
    this->nom = nomJoueur;
    this->Vie = VieJoueur;
    this->Energie = EnergieJoueur;
    this->Attaque = AttaqueJoueur;
}

Joueurs::~Joueurs(){
    cout << "Destruction de " << nom << endl;
}

Heros::Heros(){
    nomHeros = "Inconnu";
    VieHeros = 0;
    EnergieHeros = 0;
    AttaqueHeros = 0;
}

Heros::Heros(string nom, int Vie, int Energie, int Attaque){
    this->nom = nomHeros;
    this->Vie = VieHeros;
    this->Energie = EnergieHeros;
    this->Attaque = AttaqueHeros;
}

Heros::~Heros(){
    cout << "Destruction de " << nom << endl;
}

void Heros::afficher(){
    cout << "Nom : " << nomHeros << endl;
    cout << "Vie : " << VieHeros << endl;
    cout << "Energie : " << EnergieHeros << endl;
    cout << "Attaque : " << AttaqueHeros << endl;
}

void Heros::attaquer(Joueurs &cible){
    cible.recevoirDegats(Attaque);
}

void Heros::recevoirDegats(int degats){
    VieHeros -= degats;
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

vilain::vilain()( nom, int Vie, int Energie, int Attaque){
    this->nom = nomVilain;
    this->Vie = VieVilain ;
    this->Energie = EnergieVilain;
    this->Attaque = AttaqueVilain;
}

vilain::~vilain(){
    cout << "Destruction de " << nom << endl;
}

void Vilain::afficher(){
    cout << "Nom : " << nomVilain << endl;
    cout << "Vie : " << VieVilain << endl;
    cout << "Energie : " << EnergieVilain << endl;
    cout << "Attaque : " << AttaqueVilain << endl;
}

void Vilain::attaquer(Joueurs &cible){
    cible.recevoirDegats(Attaque);
}

void Vilain ::recevoirDegats(int degats){
    VieVilain -= degats;
}

bool Vilain::estVivant(){
    return VieVilain > 0;
}


