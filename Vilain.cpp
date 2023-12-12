#include "Vilain.hpp"

Vilain::Vilain(string n, int hp, int atk, int arm, int spe, int man, int cost1, int cost2, int cost3, int cdult, string at1, string at2, string at3, string ult) : Joueur(n, hp, atk, arm, spe, man, cdult) {
    attack1 = at1;
    attack2 = at2;
    attack3 = at3;
    manacost_attack1 = cost1;
    manacost_attack2 = cost2;
    manacost_attack3 = cost3;
}

Vilain::~Vilain() {}

string Vilain::get_attack1() {
    return attack1;
}

string Vilain::get_attack2() {
    return attack2;
}

string Vilain::get_attack3() {
    return attack3;
}

int Vilain::get_damage_attack1() {
    return damage_attack1;
}

int Vilain::get_damage_attack2() {
    return damage_attack2;
}

int Vilain::get_damage_attack3() {
    return damage_attack3;
}

int Vilain::get_manacost_attack1() {
    return manacost_attack1;
}

int Vilain::get_manacost_attack2() {
    return manacost_attack2;
}

int Vilain::get_manacost_attack3() {
    return manacost_attack3;
}

int Vilain::set_attack1() {
    return get_attack() + 10;
}

int Vilain::set_attack2() {
    return get_attack() + 25;
}

int Vilain::set_attack3() {
    return get_attack() + 50;
}

int Vilain::set_manacost_attack1(int mana) {
    return mana;
}

int Vilain::set_manacost_attack2(int mana) {
    return mana;
}

int Vilain::set_manacost_attack3(int mana) {
    return mana;
}
