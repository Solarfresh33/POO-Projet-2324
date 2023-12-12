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
    int manacost_attack1;
    int manacost_attack2;
    int manacost_attack3;
public:

    Vilain(string n, int hp, int atk, int arm, int spe, int man, int cost1, int cost2, int cost3, int cdult, string at1, string at2, string at3, string ult);
    ~Vilain();

    string get_attack1();
    string get_attack2();
    string get_attack3();

    int get_damage_attack1();
    int get_damage_attack2();
    int get_damage_attack3();

    int get_manacost_attack1();
    int get_manacost_attack2();
    int get_manacost_attack3();

    int set_attack1();
    int set_attack2();
    int set_attack3();

    int set_manacost_attack1(int mana);
    int set_manacost_attack2(int mana);
    int set_manacost_attack3(int mana);
};
#endif