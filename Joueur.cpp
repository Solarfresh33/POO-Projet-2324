#include "Joueur.hpp"

Joueur::Joueur(string n, int hp, int Attq, int eng) {
    nom = n;
    Vie = hp;
    Attaque = Attq;
    energie = eng;
}

Joueur::~Joueur() {}

string Joueur::get_nom() {
    return nom;
}



int Joueur::get_Vie() {
    return Vie;
}

int Joueur::get_Attaque() {
    return Attaque;
}

int Joueur::get_energie() {
    return energie;
}

void Joueur::set_Vie(int hp) {
    Vie = hp;
    if (Vie > maxVie) { // modifier maxenergie
        Vie = maxVie;
    }
}

void Joueur::set_Attaque(int Attq) {
    Attaque = Attq;
}

void Joueur::set_energie(int eng) {
    energie = eng;
}

int Joueur::regen_energie(int pourcentage) { //regenere energie
    int pourcent = pourcentage / 100;
    energie += static_cast<int>(maxenergie * pourcent);
    if (energie > maxenergie) {
        energie = maxenergie;
    }
    return energie;
}
