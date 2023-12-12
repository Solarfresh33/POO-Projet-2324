#ifndef Jeu_hpp
#define Jeu_hpp

using namespace std;

#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

class Joueurs{
protected:
    string nom; // Nom du personnage
    int Vie; // Nombre de points de vie du personnage
    int Energie; // Nombre de points d'energie du personnage
    int Attaque; // Nombre de degats du personnage

public:
    Joueurs();
    Joueurs(string nom, int Vie, int Energie, int Attaque);
    ~Joueurs();
    void afficher();
    void attaquer(Joueurs &cible);
    void recevoirDegats(int degats);
    bool estVivant();
};

class MBuf : public std::stringbuf {
public:
	int sync() {
		fputs(str().c_str(), stdout);
		str("");
		return 0;
	}
};

class Heros : public Joueurs{
public:
    Heros();
    Heros(string nom, int Vie, int Energie, int Attaque);
    ~Heros();
    virtual void afficher();
    virtual void attaquer(Joueurs &cible);
    virtual void recevoirDegats(int degats);
    virtual bool estVivant();
};

class vilain : public Joueurs{
public:
    vilain();
    vilain(string nom, int Vie, int Energie, int Attaque);
    ~vilain();
    virtual void afficher();
    virtual void attaquer(Joueurs &cible);
    virtual void recevoirDegats(int degats);
    virtual bool estVivant();
};

#endif