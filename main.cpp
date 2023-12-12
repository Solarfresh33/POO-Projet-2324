#include "Gentil.hpp"
#include "Vilain.hpp"
#include "Joueur.hpp"

using namespace std;

void printCharList(vector<Gentil> Gentillist, vector<Vilain> Vilainlist, bool isGentil) {
    if (isGentil) {
        if (Gentillist.size() == 0) {
            std::cout << "Votre liste de Gentil est vide !" << endl;
        }
        else {
            for (int i = 0; i <= Gentillist.size() - 1; i++) {
                using namespace std;
                std::cout << std::endl;
            }
        }
    }
    else {
        if (Vilainlist.size() == 0) {
            std::cout << "Votre liste de Vilain est vide !" << endl;
        }
        else {
            for (int i = 0; i <= Vilainlist.size() - 1; i++) {
                std::cout << std::endl;
            }
        }
    }
}

void printStat(Joueur p) {
    std::cout << std::endl;
    std::cout << "Vie restante : " << p.get_vie() << "/" << p.get_maxvie() << std::endl;
    std::cout << "Attaque : " << p.get_attaque() << std::endl;
    
    if (p.get_maxenergie() > 0) {
        std::cout << "Mana restant : " << p.get_energie() << "/" << p.get_maxenergie() << std::endl;
    }
    std::cout << std::endl;
}


Gentil suggestGentilChoice(string name, vector<Gentil>& Gentillist, vector<Vilain>& Vilainlist) {
    int h;
    std::cout << name << ") Vous etes un Gentil" << endl;
    while (true) {
        std::cout << name << ") Choisissez un Gentil parmi la liste suivante :" << endl;
        printCharList(Gentillist, Vilainlist, true);
        cin >> h;
        if (h >= 0 && h < Gentillist.size()) {
            Gentil p1c = Gentillist[h];
            std::cout << name << ") Vous avez choisi " << p1c.get_nom() << endl;
            return p1c;
        }
        else {
            std::cout << "Votre choix ne figure pas dans la liste." << endl;
        }
    }
}


Vilain suggestVilainChoice(string name, vector<Gentil> Gentillist, vector<Vilain> Vilainlist) {
    int h;
    std::cout << name << ") Vous etes un Vilain" << endl;
    while (true) {
        std::cout << name << ") Choisissez un Vilain parmis la liste suivante :" << endl;
        printCharList(Gentillist, Vilainlist, false);
        cin >> h;
        if (h > Gentillist.size() - 1) {
            std::cout << "Votre personnage ne figure pas dans la liste !" << endl;
        }
        else {
            Vilain p2c = Vilainlist[h];
            std::cout << name << ") Vous avez choisi " << p2c.get_nom() << endl;
            return p2c;
        }

    }
}

void checkWin(Joueur& p1, Joueur& p2, string p1name, string p2name) {
    if (p1.get_vie() <= 0 && p1.has_revive()) {
            if (p1.get_nom() == "Eren") {
                std::cout << p1.get_nom() << " :Je débarasserai la Terre de tous les titans !" << endl;
                std::cout << p1name << " se releve de ses blessures !" << endl;
                p1.set_maxenergie(p1.get_maxenergie() - 400);
                p1.set_maxvie(75);
                p1.set_vie(75);
                std::cout << p1name << ") -400 Mana Max" << endl;
                std::cout << p1name << ") " << p1.get_vie() << "/" << p1.get_maxvie() << "PV" << endl;
            }
            else if (p1.get_nom() == "Izuku") {
                std::cout << p1.get_nom() << " : Je serai un héros qui garde le sourire, peu importe la situation !" << endl;
                std::cout << p1name << " se releve de ses blessures !" << endl;
                p1.set_maxvie(95);
                p1.set_vie(95);
                std::cout << p1name << ") " << p1.get_vie() << "/" << p1.get_maxvie() << "PV" << endl;
            }
            p1.can_revive(false);
        }
    }
    void checkWin(Joueur& p1, Joueur& p2, string p1name, string p2name) {
        if (p1.get_vie() <= 0) {
            std::cout << "Victoire de " << p1name << endl;
            exit(0);
        }
        else if (p2.get_vie() <= 0) {
            std::cout << "Victoire de " << p2name << endl;
            exit(0);
        }
    }


int makeGentilAction(Gentil& h, int attacksender) {
    int brutdamage;
    printf("\n");
    if (h.get_action() == 1) {
        brutdamage = h.set_fight1();
        h.set_energie(h.get_energie() - h.get_perteenergie_fight1());
        std::cout << h.get_fight1() << " !" << endl;
    }
    else if (h.get_action() == 2) {
        brutdamage = h.set_fight2();
        h.set_energie(h.get_energie() - h.get_perteenergie_fight2());
        std::cout << h.get_fight2() << " !" << endl;
    }
    else if (h.get_action() == 3) {
        brutdamage = h.set_fight3();
        h.set_energie(h.get_energie() - h.get_perteenergie_fight3());
        std::cout << h.get_fight3() << " !" << endl;
    }
    return brutdamage;
}

int makeVilainAction(Vilain& m, int attacksender) {
    int brutdamage;
    printf("\n");
    if (m.get_action() == 1) {
        brutdamage = m.set_attack();
        m.set_energie(m.get_energie() - m.get_coutenergie1());
        std::cout << m.get_attack() << " !" << endl;
    }
    else if (m.get_action() == 2) {
        brutdamage = m.set_attack2();
        m.set_energie(m.get_energie() - m.get_coutenergie2());
        std::cout << m.get_attack2() << " !" << endl;
    }
    else if (m.get_action() == 3) {
        brutdamage = m.set_attack3();
        m.set_energie(m.get_energie() - m.get_coutenergie3());
        std::cout << m.get_attack3() << " !" << endl;
    }
    return brutdamage;
}

int chooseGentilAttack(Gentil& h, string name) {
    int action;
    while (true) {
        std::cout << name << ") Quel attaque souhaitez-vous faire ?" << endl;
        if (h.get_maxenergie() > 0) {
            std::cout << "1 - " << h.get_fight1() << " | Mana : " << h.get_perteenergie_fight1() << endl;
            std::cout << "2 - " << h.get_fight2() << " | Mana : " << h.get_perteenergie_fight2() << endl;
            std::cout << "3 - " << h.get_fight3() << " | Mana : " << h.get_perteenergie_fight3() << endl;
        }
        else {
            std::cout << "1 - " << h.get_fight1() << endl;
            std::cout << "2 - " << h.get_fight2() << endl;
            std::cout << "3 - " << h.get_fight3() << endl;
        }
        if (action == 1) {
            if (h.get_energie() < h.get_perteenergie_fight1()) {
                std::cout << "Action 1 selected." << endl;
                std::cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;    
            }
        }
        else if (action == 2) {
            if (h.get_energie() < h.get_perteenergie_fight2()) {
                std::cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 3) {
            if (h.get_energie() < h.get_perteenergie_fight3()) {
                std::cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        printf("\n");
        if (action == 1) {
            if (h.get_maxenergie() > 0) {
                std::cout << name << ") -" << h.get_perteenergie_fight1() << " Mana" << endl;
            }
        }
        else if (action == 2) {
            if (h.get_maxenergie() > 0) {
                std::cout << name << ") -" << h.get_perteenergie_fight2() << " Mana" << endl;
            }
        }
        else if (action == 3) {
            if (h.get_maxenergie() > 0) {
                std::cout << name << ") -" << h.get_perteenergie_fight3() << " Mana" << endl;
            }
        }
        h.set_action(action);
        return makeGentilAction(h, 1);
    }
}


int chooseVilainAttack(Vilain& m, string name) {
    int action;
    while (true) {
        std::cout << name << ") Quel attaque souhaitez-vous faire ?" << endl;
        if (m.get_maxenergie() > 0) {
            std::cout << "1 - " << m.get_attack() << " | Mana : " << m.get_coutenergie1() << endl;
            std::cout << "2 - " << m.get_attack2() << " | Mana : " << m.get_coutenergie2() << endl;
            std::cout << "3 - " << m.get_attack3() << " | Mana : " << m.get_coutenergie3() << endl;
        }
        else {
            std::cout << "1 - " << m.get_attack() << endl;
            std::cout << "2 - " << m.get_attack2() << endl;
            std::cout << "3 - " << m.get_attack3() << endl;
        }
        if (action == 1) {
            if (m.get_energie() < m.get_coutenergie1()) {
                std::cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 2) {
            if (m.get_energie() < m.get_coutenergie2()) {
                std::cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 3) {
            if (m.get_energie() < m.get_coutenergie3()) {
                std::cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        printf("\n");
        if (action == 1) {
            if (m.get_maxenergie() > 0) {
                std::cout << name << ") -" << m.get_coutenergie1() << " Mana" << endl;
            }
        }
        else if (action == 2) {
            if (m.get_maxenergie() > 0) {
                std::cout << name << ") -" << m.get_coutenergie2() << " Mana" << endl;
            }
        }
        else if (action == 3) {
            if (m.get_maxenergie() > 0) {
                std::cout << name << ") -" << m.get_coutenergie3() << " Mana" << endl;
            }
        }
        m.set_action(action);
        return makeVilainAction(m, 2);
    }


}

int main() {
    vector<Gentil> Gentillist;
    vector<Vilain> Vilainlist;

    string p1 = "Joueur 1";
    std::cout << p1 << " quel est votre pseudo ?" << endl;
    cin >> p1;
    string p2 = "Joueur 2";
    std::cout << p2 << " quel est votre pseudo ?" << endl;
    cin >> p2;

    Gentil p1c = Gentil("Izuku", 200, 40, 25, 30, 250, 20, 50, 100, 3, "Detroit Smash", "Delaware Smash", "Texas Smash", "Delaware Detroit Smash");
    Gentillist.push_back(p1c);
    Gentil p1c = Gentil("Zoro", 250, 35, 40, 30, 70, 25, 35, 50, 3, "Santoryu : Ittoryu Iai : Shishi Sonson", "Santoryu : Nitoryu : 108 Pound Phoenix", "Santoryu : Kyutoryu : Asura", "Santoryu : Sanzen Sekai");
    Gentillist.push_back(p1c);
    Gentil p1c = Gentil("Naruto", 230, 35, 10, 35, 800, 35, 75, 250, 5, "Rasengan", "Futon : Rasen-Shuriken", "Rikudo : Orbe du demon a 9 queues", "Additional Technique");
    Gentillist.push_back(p1c);


    Vilain p2c = Vilain("Eren", 240, 50, 35, 55, 0, 0, 0, 0, 3, "Voltige : Equipement tridimensionnel avec lames", "Voltige : equipement tridimensionnel avec lance explosive", "Poing de l'originel");
    Vilainlist.push_back(p2c);
    Vilain p2c = Vilain("Zeleph", 190, 55, 25, 75, 100, 25, 30, 45, 4, "Vague de la mort", "Orbe de la Mort", "Pilier de la Mort");  
    Vilainlist.push_back(p2c);
    Vilain p2c = Vilain("Sukuna", 150, 50, 20, 40, 700, 50, 75, 300, 4, "Dissection", "Laceration", "Toile d'araignée");
    Vilainlist.push_back(p2c);
    int HMchoice;
    int brutdamage;
    printf("\n");
    if (HMchoice == 1) {
        Gentil p1c = suggestGentilChoice(p1, Gentillist, Vilainlist);
        printf("\n");
        Vilain p2c = suggestVilainChoice(p2, Gentillist, Vilainlist);
        checkWin(p1c, p2c, p1, p2);
        }
    }
    else if (HMchoice == 2) {
        p1c = suggestVilainChoice(p1, Gentillist, Vilainlist);
        Gentil p2c = suggestGentilChoice(p2, Gentillist, Vilainlist);
    }
        while (true) {
            if (p1c.get_fight1() >= p2c.get_attack()) {
                printStat(p1c);
                brutdamage = chooseVilainAttack(p1c, p1);
                printStat(p2c);
                brutdamage = chooseGentilAttack(p2c, p2);
            }
            else {
                printStat(p2c);
                brutdamage = chooseGentilAttack(p2c, p2);
                printStat(p1c);
                brutdamage = chooseVilainAttack(p1c, p1);
            }
        }