#ifndef JOUEUR
#define JOUEUR

#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
using namespace std;

class Joueur {
protected:
	string name;
	int maxhealth;
	int health;
	int attack;
	int armor;
	int speed;
	int maxmana;
	int mana;
	int action;
	bool revive = false;
public:
	Joueur(string n, int hp, int atk, int arm, int spe, int man);
	~Joueur();

	string get_name();
	int get_maxhealth();
	int get_health();
	int get_attack();
	int get_armor();
	int get_speed();
	int get_maxmana();
	int get_mana();
	int get_action();

	void set_maxhealth(int hpmax);
	void set_health(int hp);
	void set_attack(int atk);
	void set_armor(int arm);
	void set_speed(int spe);
	void set_maxmana(int manmax);
	void set_mana(int man);
	void set_action(int act);
	
	int regen_mana(int pourcentage);
	void can_revive(bool rev);
	bool has_revive();
};
#endif // !Joueur
