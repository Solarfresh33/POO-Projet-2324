#ifndef JOUEUR
#define JOUEUR

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>
using namespace std;

class Joueur {
protected:
	string nom;
	int maxvie;
	int vie;
	int attaque;
	int maxenergie;
	int energie;
	int action;
	bool revive = false;
public:
	Joueur(string n, int hp, int atk, int eng);
	~Joueur();

	string get_nom();
	int get_maxvie();
	int get_vie();
	int get_attaque();
	int get_maxenergie();
	int get_energie();
	int get_action();

	void set_maxvie(int hpmax);
	void set_vie(int hp);
	void set_attaque(int atk);
	void set_maxenergie(int manmax);
	void set_energie(int eng);
	void set_action(int act);

	int regen_energie(int pourcentage);
	void can_revive(bool rev);
	bool has_revive();
};
#endif // !Joueur
