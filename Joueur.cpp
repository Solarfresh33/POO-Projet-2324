#include "Joueur.hpp"

Joueur::Joueur(string n, int hp, int Attq, int eng) {
    nom = n;
    vie = hp;
    attaque = Attq;
    energie = eng;
}

Joueur::~Joueur() {}

string Joueur::get_nom() {
    return nom;
}



int Joueur::get_vie() {
    return vie;
}

int Joueur::get_attaque() {
    return attaque;
}

int Joueur::get_energie() {
    return energie;
}

void Joueur::set_vie(int hp) {
    vie = hp;
    if (vie > maxvie) { // modifier maxvie
        vie = maxvie;
    }
}

void Joueur::set_attaque(int Attq) {
    attaque = Attq;
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
