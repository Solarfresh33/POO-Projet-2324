#include "Gentil.hpp"

Gentil::Gentil(string n, int hp, int atk, int arm, int spe, int man, int en1, int en2, int en3, string fight1, string fight2, string fight3) : Joueur(n, hp, atk, arm, spe, man);
    Attaque = fight1;
    Attaque = fight2;
    Attaque = fight3;
   energie_fight1 = perteEN1; // à voir ce que c'est
   perteenergie_fight2 = perteEN2;
   perteenergie_fight3 = perteEN3;
}


Gentil::~Gentil() {}

string Gentil::get_fight1() {
    return fight1;
}

string Gentil::get_fight2() {
    return fight2;
}

string Gentil::get_fight3() {
    return fight3;
}

int Gentil::get_degats_fight1() {
    return degats_fight1;
}

int Gentil::get_degats_fight2() {
    return degats_fight2;
}

int Gentil::get_degats_fight3() {
    return degats_fight3;
}

int Gentil::get_forceen_fight1() {
    returnenergie_fight1;
}

int Gentil::get_forceen_fight2() {
    returnenergie_fight2;
}

int Gentil::get_forceen_fight3() {
    returnenergie_fight3;
}

int Gentil::set_forceen_fight1(int force) {
    return force;
}

int Gentil::set_forceen_fight2(int force) {
    return force;
}

int Gentil::set_forceen_fight3(int force) {
    return force;
}
