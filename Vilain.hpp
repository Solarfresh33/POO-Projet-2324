#ifndef VILAIN
#define VILAIN

#include "Joueur.hpp"

class Vilain : public Joueur {
protected:
    string attack1;
    string attack2;
    string attack3;
    int damage_attack1;
    int damage_attack2;
    int damage_attack3;
    int coutenergie1;
    int coutenergie2;
    int coutenergie3;
public:

    Vilain(string n, int hp, int atk, int enrgs, string at1, string at2, string at3, string ult);
    ~Vilain();

    string get_attack();
    string get_attack2();
    string get_attack3();


    int get_damage_attack1();
    int get_damage_attack2();
    int get_damage_attack3();

    int get_coutenergie1();
    int get_coutenergie2();
    int get_coutenergie3();

    int set_attack();
    int set_attack2();
    int set_attack3();

    int set_coutenergie1(int mana);
    int set_coutenergie2(int mana);
    int set_coutenergie3(int mana);

    int set_damage_attack1(int degats);
    int set_damage_attack2(int degats);
    int set_damage_attack3(int degats);

};

#endif