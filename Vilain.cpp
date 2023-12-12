#include "Vilain.hpp"

Vilain::Vilain(string n, int hp, int atk, int enrg, string at1, string at2, string at3, string ult) : Joueur(n, hp, atk, enrg) {
    attack1 = at1;
    attack2 = at2;
    attack3 = at3;
}

Vilain::~Vilain() {}

string Vilain::get_attack() {
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

int Vilain::get_coutenergie1() {
    return coutenergie1;
}

int Vilain::get_coutenergie2() {
    return coutenergie2;
}

int Vilain::get_coutenergie3() {
    return coutenergie3;
}

int Vilain::set_attack() {
    return 0;
}

int Vilain::set_attack2() {
    return 0;
}

int Vilain::set_attack3() {
    return 0;
}

int Vilain::set_damage_attack1(int degats) {
    return degats;
}

int Vilain::set_damage_attack2(int degats) {
    return degats;
}

int Vilain::set_damage_attack3(int degats) {
    return degats;
}

int Vilain::set_coutenergie1(int enrg) {
    return enrg;
}

int Vilain::set_coutenergie2(int enrg) {
    return enrg;
}

int Vilain::set_coutenergie3(int enrg) {
    return enrg;
}

