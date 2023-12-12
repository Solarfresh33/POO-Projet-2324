#ifndef GENTIL
#define GENTIL

#include "Joueur.hpp"

class Gentil : public Joueur {
protected:
    string fight1;
    string fight2;
    string fight3;
    int Attaque1;
    int Attaque2;
    int Attaque3;
    int degats_fight1;
    int degats_fight2;
    int degats_fight3;
    int Forceen_fight1;
    int Forceen_fight2;
    int Forceen_fight3;
    int perteenergie_fight1;
    int perteenergie_fight2;
    int perteenergie_fight3;


public:

    Gentil(string n, int hp, int attq, int eng);

    string get_fight1();
    string get_fight2();
    string get_fight3();

    int get_degats_fight1();
    int get_degats_fight2();
    int get_degats_fight3();

    int get_forceen_fight1();
    int get_forceen_fight2();
    int get_forceen_fight3();

    int get_perteenergie_fight1();
    int get_perteenergie_fight2();
    int get_perteenergie_fight3();

    int set_fight1();
    int set_fight2();
    int set_fight3();

    int set_degats_fight1(int degats);
    int set_degats_fight2(int degats);
    int set_degats_fight3(int degats);

    int set_forceen_fight1(int force);
    int set_forceen_fight2(int force);
    int set_forceen_fight3(int force);

    int set_perteenergie_fight1(int energie);
    int set_perteenergie_fight2(int energie);
    int set_perteenergie_fight3(int energie);
};

#endif