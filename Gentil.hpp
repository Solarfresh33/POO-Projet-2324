#ifndef GENTIL
#define GENTIL

#include "Joueur.hpp"

class Gentil : public Joueur {
protected:
    string fight1;
    string fight2;
    string fight3;
    string ultime;
    int degats_fight1;
    int degats_fight2;
    int degats_fight3;
    int perteenergie_fight1;
    int perteenergie_fight2;
    int perteenergie_fight3;


public:

    Gentil(string n, int hp, int attq, int eng, int cost1, int cost2, int cost3, int cdult, string at1, string at2, string at3, string ult);
    ~Gentil();

    string get_fight1();
    string get_fight2();
    string get_fight3();
    string get_ultime();

    int get_degats_fight1();
    int get_degats_fight2();
    int get_degats_fight3();

    int get_perteenergie_fight1();
    int get_perteenergie_fight2();
    int get_perteenergie_fight3();

    int set_fight1();
    int set_fight2();
    int set_fight3();
    int set_ultimate();

    int set_perteenergie_fight1(int energie);
    int set_perteenergie_fight2(int energie);
    int set_perteenergie_fight3(int energie);
};

#endif