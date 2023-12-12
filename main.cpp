#include "Gentil.hpp"
#include "Vilain.hpp"

void printCharList(vector<Gentil> Gentillist, vector<Vilain> Vilainlist, bool isGentil) {
    if (isGentil) {
        if (Gentillist.size() == 0) {
            cout << "Votre liste de Gentil est vide !" << endl;
        }
        else {
            for (int i = 0; i <= Gentillist.size() - 1; i++) {
                    cout << "[" << i << "] : " << Gentillist[i].get_name() << endl;
                    cout << "PV : " << Gentillist[i].get_health() << " | Attaque : " << Gentillist[i].get_attack() << " | Armure : " << Gentillist[i].get_armor() << " | Vitesse : " << Gentillist[i].get_speed() << " | Mana : " << Gentillist[i].get_mana() << endl;
                    cout << "Technique :" << endl;
                    if (Gentillist[i].get_maxmana() > 0) {
                        cout << "1 - " << Gentillist[i].get_attack1() << " | Mana : " << Gentillist[i].get_manacost_attack1() << endl;
                        cout << "2 - " << Gentillist[i].get_attack2() << " | Mana : " << Gentillist[i].get_manacost_attack2() << endl;
                        cout << "3 - " << Gentillist[i].get_attack3() << " | Mana : " << Gentillist[i].get_manacost_attack3() << endl;
                    }
                    else {
                        cout << "1 - " << Gentillist[i].get_attack1() << endl;
                        cout << "2 - " << Gentillist[i].get_attack2() << endl;
                        cout << "3 - " << Gentillist[i].get_attack3() << endl;
                    }
                    printf("\n");
                }
            }
        }
    }
    else {
        if (Vilainlist.size() == 0) {
            cout << "Votre liste de Vilain est vide !" << endl;
        }
        else {
            for (int i = 0; i <= Vilainlist.size() - 1; i++) {
                    cout << "[" << i << "] : " << Vilainlist[i].get_name() << endl;
                    cout << "PV : " << Vilainlist[i].get_health() << " | Attaque : " << Vilainlist[i].get_attack() << " | Armure : " << Vilainlist[i].get_armor() << " | Vitesse : " << Vilainlist[i].get_speed() << " | Mana : " << Vilainlist[i].get_mana() << endl;
                    cout << "Technique :" << endl;
                    if (Vilainlist[i].get_maxmana() > 0) {
                        cout << "1 - " << Vilainlist[i].get_attack1() << " | Mana : " << Vilainlist[i].get_manacost_attack1() << endl;
                        cout << "2 - " << Vilainlist[i].get_attack2() << " | Mana : " << Vilainlist[i].get_manacost_attack2() << endl;
                        cout << "3 - " << Vilainlist[i].get_attack3() << " | Mana : " << Vilainlist[i].get_manacost_attack3() << endl;
                    }
                    else {
                        cout << "1 - " << Vilainlist[i].get_attack1() << endl;
                        cout << "2 - " << Vilainlist[i].get_attack2() << endl;
                        cout << "3 - " << Vilainlist[i].get_attack3() << endl;
                    }
                    printf("\n");
                }
            }
        }
    }

}

void printStat(Joueur p) {
    printf("\n");
    cout << "Vie restante : " << p.get_health() << "/" << p.get_maxhealth() << endl;
    cout << "Attaque : " << p.get_attack() << endl;
    if (p.get_armor() > 0) {
        cout << "Armure : " << p.get_armor() << endl;
    }
    cout << "Vitesse : " << p.get_speed() << endl;
    if (p.get_maxmana() > 0) {
        cout << "Mana restant : " << p.get_mana() << "/" << p.get_maxmana() << endl;
    }
    printf("\n");
}

Gentil suggestGentilChoice(string name, vector<Gentil>& Gentillist, vector<Vilain>& Vilainlist) {
    int h;
    cout << name << ") Vous etes un Gentil" << endl;

    while (true) {
        cout << name << ") Choisissez un Gentil parmi la liste suivante :" << endl;
        printCharList(Gentillist, Vilainlist, true);
        cin >> h;

        if (h >= 0 && h < Gentillist.size()) {
            Gentil p1c = Gentillist[h];
            cout << name << ") Vous avez choisi " << p1c.get_name() << endl;
            return p1c;
        }
        else {
            cout << "Votre choix ne figure pas dans la liste !" << endl;
        }
    }
}


Vilain suggestVilainChoice(string name, vector<Gentil> Gentillist, vector<Vilain> Vilainlist) {
    int h;
    cout << name << ") Vous etes un Vilain" << endl;
    while (true) {
        cout << name << ") Choisissez un Vilain parmis la liste suivante :" << endl;
        printCharList(Gentillist, Vilainlist, false);
        cin >> h;
        if (h > Gentillist.size() - 1) {
            cout << "Votre choix ne figure pas dans la liste !" << endl;
        }
        else {
            Vilain p2c = Vilainlist[h];
            cout << name << ") Vous avez choisit " << p2c.get_name() << endl;
            return p2c;
        }

    }
}

void checkWin(Joueur& p1, Joueur& p2, string p1name, string p2name) {
    if (p1.get_health() <= 0 && p1.has_revive()) {
            if (p1.get_name() == "Eren") {
                cout << p1.get_name() << " :Je débarasserai la Terre de tous les titans !" << endl;
                cout << p1name << " se releve de ses blessures !" << endl;
                p1.set_maxmana(p1.get_maxmana() - 400);
                p1.set_maxhealth(75);
                p1.set_health(75);
                cout << p1name << ") -400 Mana Max" << endl;
                cout << p1name << ") " << p1.get_health() << "/" << p1.get_maxhealth() << "PV" << endl;
            }
            else if (p1.get_name() == "Izuku") {
                cout << p1.get_name() << " : Je serai un héros qui garde le sourire, peu importe la situation !" << endl;
                cout << p1name << " se releve de ses blessures !" << endl;
                p1.set_maxhealth(95);
                p1.set_health(95);
                cout << p1name << ") " << p1.get_health() << "/" << p1.get_maxhealth() << "PV" << endl;
            }
            p1.can_revive(false);
        }
    }
    if (p1.get_health() <= 0) {
        cout << "Victoire de " << p1name << endl;
        exit(0);
    }
    else if (p2.get_health() <= 0) {
        cout << "Victoire de " << p2name << endl;
        exit(0);
    }
}

int makeGentilAction(Gentil& h, int attacksender) {
    int brutdamage;
    printf("\n");
    if (h.get_action() == 1) {
        brutdamage = h.set_attack1();
        h.set_mana(h.get_mana() - h.get_manacost_attack1());
        cout << h.get_attack1() << " !" << endl;
    }
    else if (h.get_action() == 2) {
        brutdamage = h.set_attack2();
        h.set_mana(h.get_mana() - h.get_manacost_attack2());
        cout << h.get_attack2() << " !" << endl;
    }
    else if (h.get_action() == 3) {
        brutdamage = h.set_attack3();
        h.set_mana(h.get_mana() - h.get_manacost_attack3());
        cout << h.get_attack3() << " !" << endl;
    }
    else if (h.get_action() == 0) {
        brutdamage = h.set_ultimate();
        cout << h.get_ultime() << " !" << endl;
    }
    return brutdamage;
}

int makeVilainAction(Vilain& m, int attacksender) {
    int brutdamage;
    printf("\n");
    if (m.get_action() == 1) {
        brutdamage = m.set_attack1();
        m.set_mana(m.get_mana() - m.get_manacost_attack1());
        cout << m.get_attack1() << " !" << endl;
    }
    else if (m.get_action() == 2) {
        brutdamage = m.set_attack2();
        m.set_mana(m.get_mana() - m.get_manacost_attack2());
        cout << m.get_attack2() << " !" << endl;
    }
    else if (m.get_action() == 3) {
        brutdamage = m.set_attack3();
        m.set_mana(m.get_mana() - m.get_manacost_attack3());
        cout << m.get_attack3() << " !" << endl;
    }
    else if (m.get_action() == 0) {
        brutdamage = m.set_ultimate();
        cout << m.get_ultime() << " !" << endl;
    }
    return brutdamage;
}

int chooseGentilAttack(Gentil& h, string name) {
    int action;
    while (true) {
        cout << name << ") Quel attaque souhaitez-vous faire ?" << endl;
        if (h.get_maxmana() > 0) {
            cout << "1 - " << h.get_attack1() << " | Mana : " << h.get_manacost_attack1() << endl;
            cout << "2 - " << h.get_attack2() << " | Mana : " << h.get_manacost_attack2() << endl;
            cout << "3 - " << h.get_attack3() << " | Mana : " << h.get_manacost_attack3() << endl;
        }
        else {
            cout << "1 - " << h.get_attack1() << endl;
            cout << "2 - " << h.get_attack2() << endl;
            cout << "3 - " << h.get_attack3() << endl;
        }
        else if (action == 1) {
            if (h.get_mana() < h.get_manacost_attack1()) {
                cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 2) {
            if (h.get_mana() < h.get_manacost_attack2()) {
                cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 3) {
            if (h.get_mana() < h.get_manacost_attack3()) {
                cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        printf("\n");
        if (action == 1) {
            if (h.get_maxmana() > 0) {
                cout << name << ") -" << h.get_manacost_attack1() << " Mana" << endl;
            }
        }
        else if (action == 2) {
            if (h.get_maxmana() > 0) {
                cout << name << ") -" << h.get_manacost_attack2() << " Mana" << endl;
            }
        }
        else if (action == 3) {
            if (h.get_maxmana() > 0) {
                cout << name << ") -" << h.get_manacost_attack3() << " Mana" << endl;
            }
        }
        h.set_action(action);
        return makeGentilAction(h, h.get_attack());
    }
}

int chooseVilainAttack(Vilain& m, string name) {
    int action;
    while (true) {
        cout << name << ") Quel attaque souhaitez-vous faire ?" << endl;
        if (m.get_maxmana() > 0) {
            cout << "1 - " << m.get_attack1() << " | Mana : " << m.get_manacost_attack1() << endl;
            cout << "2 - " << m.get_attack2() << " | Mana : " << m.get_manacost_attack2() << endl;
            cout << "3 - " << m.get_attack3() << " | Mana : " << m.get_manacost_attack3() << endl;
        }
        else {
            cout << "1 - " << m.get_attack1() << endl;
            cout << "2 - " << m.get_attack2() << endl;
            cout << "3 - " << m.get_attack3() << endl;
        }
        else if (action == 1) {
            if (m.get_mana() < m.get_manacost_attack1()) {
                cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 2) {
            if (m.get_mana() < m.get_manacost_attack2()) {
                cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        else if (action == 3) {
            if (m.get_mana() < m.get_manacost_attack3()) {
                cout << "Vous n'avez pas assez d'energie pour utiliser cette Technique !" << endl;
                continue;
            }
        }
        printf("\n");
        if (action == 1) {
            if (m.get_maxmana() > 0) {
                cout << name << ") -" << m.get_manacost_attack1() << " Mana" << endl;
            }
        }
        else if (action == 2) {
            if (m.get_maxmana() > 0) {
                cout << name << ") -" << m.get_manacost_attack2() << " Mana" << endl;
            }
        }
        else if (action == 3) {
            if (m.get_maxmana() > 0) {
                cout << name << ") -" << m.get_manacost_attack3() << " Mana" << endl;
            }
        }
        m.set_action(action);
        return makeVilainAction(m, m.get_attack());
    }


}
void makeArmor(int action, Joueur& p, int brutdamage, Joueur& p2, string p1name, string p2name) {
    int damage;
    printf("\n");
    if (action == 1) {
        damage = p.encaisser(p.get_armor(), brutdamage);
        p.set_health(p.get_health() - damage);
    }
    else if (action == 2) {
        damage = p.esquive(p.get_armor(), p.get_speed(), brutdamage);
        if (damage == 0) {
            p.set_speed(p.get_speed() - 5);
            cout << p1name << ") " << p2.get_speed() << "Vitesse (-5 Vitesse)" << endl;
        }
        else {
            p.set_health(p.get_health() - damage);
        }
    }
    else if (action == 3) {
        damage = p.parer(p.get_armor(), brutdamage);
        if (damage == brutdamage / 4) {
            p.set_health(p.get_health() - damage);
            p.set_armor(p.get_armor() - 15);
            p2.set_health(p2.get_health() - damage);
            cout << p1name << ") " << p2.get_health() << "/" << p2.get_maxhealth() << " (-" << damage << " PV)" << endl;
            cout << p1name << ") " << p2.get_armor() << "Armure (-15 Armure)" << endl;
        }
    }
    if (damage > 0) {
        cout << p2name << ") " << p.get_health() << "/" << p.get_maxhealth() << " (-" << damage << " PV)" << endl;
    }
    checkWin(p, p2, p1name, p2name);
    if (damage > 0 || damage == brutdamage / 4) {
        if (p2.get_name() == "Shigaraki") {
            float pourcent = 10.0 / 100;
            int malus_health = static_cast<int>(p.get_maxhealth() * pourcent);
            p.set_maxhealth(p.get_maxhealth() - malus_health);
            cout << "Desintegration" << endl;
            cout << p1name << ") " << "(-" << malus_health << " PV Max)" << endl;
        }

    }
    checkWin(p, p2, p1name, p2name);
}

void resetround(Gentil& p1, Vilain& p2) {
    p1.regen_mana(10);
    p2.regen_mana(10);

    if (p2.get_name() == "") {
        if (p1.get_name() != "Zoro") {
            p2.set_health(p2.get_health() + 100);
            cout << "" << endl;
        }
        else {
            cout << "" << endl;
        }
    }
    else if (p1.get_name() == "Eren") {
        if (p1.get_mana() <= 45) {
            p1.set_speed(p1.get_attack() - 25);
            cout << "Malus d'attaque (-25 Attaque)" << endl;
        }
        else {
            p1.set_speed(p1.get_speed() + 25);
            cout << "Bonus d'attaque (+25 Attaque)" << endl;
        }
    }
    else if (p1.get_name() == "Izuku") {
        float pourcent = 5.0 / 100;
        int buff_attack = static_cast<int>(p1.get_attack() * pourcent);
        int buff_armor = static_cast<int>(p1.get_armor() * pourcent);
        int buff_speed = static_cast<int>(p1.get_speed() * pourcent);
        p1.set_attack(p1.get_attack() + buff_attack);
        p1.set_armor(p1.get_armor() + buff_armor);
        p1.set_speed(p1.get_speed() + buff_armor);
        cout << "One For All ! Revetement Integral : " << (p1.get_attack() + p1.get_armor() + p1.get_speed()) / 3 << " %" << endl;
        cout << "+ " << buff_attack << " Attaque" << endl;
        cout << "+ " << buff_armor << " Armure" << endl;
        cout << "+ " << buff_speed << " Vitesse" << endl;
    }
}

int main() {
    vector<Gentil> Gentillist;
    vector<Vilain> Vilainlist;

    string p1 = "Joueur 1";
    cout << p1 << " quel est votre pseudo ?" << endl;
    cin >> p1;
    string p2 = "Joueur 2";
    cout << p2 << " quel est votre pseudo ?" << endl;
    cin >> p2;

    Gentil izuku = Gentil("Izuku", 200, 40, 25, 30, 250, 20, 50, 100, 3, "Detroit Smash", "Delaware Smash", "Texas Smash", "Delaware Detroit Smash");
    izuku.set_passif("One For All : Izuku gagnera 5% de sa force, de son armure et de sa vitesse a chaque tour");
    Gentillist.push_back(izuku);
    Gentil zoro = Gentil("Zoro", 250, 35, 40, 30, 70, 25, 35, 50, 3, "Santoryu : Ittoryu Iai : Shishi Sonson", "Santoryu : Nitoryu : 108 Pound Phoenix", "Santoryu : Kyutoryu : Asura", "Santoryu : Sanzen Sekai");
    Gentillist.push_back(zoro);
    Gentil naruto = Gentil("Naruto", 230, 35, 10, 35, 800, 35, 75, 250, 5, "Rasengan", "Futon : Rasen-Shuriken", "Mode Ermite : Rasen-Shuriken", "Rikudo : Orbe du demon a 9 queues");
    Gentillist.push_back(Naruto);


    Vilain toji = Vilain("Eren", 240, 50, 35, 55, 0, 0, 0, 0, 3, "Voltige : Equipement tridimensionnel avec lames", "Voltige : equipement tridimensionnel avec lance explosive", "Poing de l'originel", "Determination de l'originel");
    Vilainlist.push_back(Eren);
    Vilain shigaraki = Vilain("Shigaraki", 180, 45, 15, 25, 350, 30, 65, 125, 4, "", "Decomposition", "Onde de Choc Desintegrante", "Regeneration Anormale");
    Vilainlist.push_back(shigaraki);
    Vilain Zeleph = Vilain("", 190, 55, 25, 75, 100, 25, 30, 45, 4, "", "", "", "");  
    Vilainlist.push_back(zeleph);
    Vilain sukuna = Vilain("Sukuna", 150, 50, 20, 40, 700, 50, 75, 300, 4, "", "", "", "");
    sukuna.can_revive(true);
    Vilainlist.push_back(sukuna);
    int HMchoice;
    while (true) {
        cout << p1 << ") Gentil(1) ou Vilain(2) ?" << endl;
        cin >> HMchoice;
        if (HMchoice < 1 || HMchoice > 2) {
            cout << "Vous devez choisir Gentil(1) ou Vilain(2) !" << endl;
        }
        else {
            break;
        }
    }


    int armor;
    int brutdamage;
    printf("\n");
    if (HMchoice == 1) {
        Gentil p1c = suggestGentilChoice(p1, Gentillist, Vilainlist);
        printf("\n");
        Vilain p2c = suggestVilainChoice(p2, Gentillist, Vilainlist);
        checkWin(p1c, p2c, p1, p2);
        }
        while (true) {
            if (p1c.get_speed() >= p2c.get_speed()) {
                printStat(p1c);
                brutdamage = chooseGentilAttack(p1c, p1);
                armor = chooseArmor(p2c, p1c, p2);
                makeArmor(armor, p2c, brutdamage, p1c, p1, p2);
                printStat(p2c);
                brutdamage = chooseVilainAttack(p2c, p2);
                armor = chooseArmor(p1c, p2c, p1);
                makeArmor(armor, p1c, brutdamage, p2c, p2, p1);
                resetround(p1c, p2c);
            }
            else {
                printStat(p2c);
                brutdamage = chooseVilainAttack(p2c, p2);
                armor = chooseArmor(p1c, p2c, p1);
                makeArmor(armor, p1c, brutdamage, p2c, p2, p1);
                printStat(p1c);
                brutdamage = chooseGentilAttack(p1c, p1);
                armor = chooseArmor(p2c, p1c, p2);
                makeArmor(armor, p2c, brutdamage, p1c, p1, p2);
                resetround(p1c, p2c);
            }
        }

    }
    else if (HMchoice == 2) {
        Vilain p1c = suggestVilainChoice(p1, Gentillist, Vilainlist);
        printf("\n");
        Gentil p2c = suggestGentilChoice(p2, Gentillist, Vilainlist);
            checkWin(p2c, p1c, p2, p1);
        }
        while (true) {
            if (p1c.get_speed() >= p2c.get_speed()) {
                printStat(p1c);
                brutdamage = chooseVilainAttack(p1c, p1);
                armor = chooseArmor(p2c, p1c, p2);
                makeArmor(armor, p2c, brutdamage, p1c, p2, p1);
                printStat(p2c);
                brutdamage = chooseGentilAttack(p2c, p2);
                armor = chooseArmor(p1c, p2c, p1);
                makeArmor(armor, p1c, brutdamage, p2c, p1, p2);
                resetround(p2c, p1c);
            }
            else {
                printStat(p2c);
                brutdamage = chooseGentilAttack(p2c, p2);
                armor = chooseArmor(p1c, p2c, p1);
                makeArmor(armor, p1c, brutdamage, p2c, p1, p2);
                printStat(p1c);
                brutdamage = chooseVilainAttack(p1c, p1);
                armor = chooseArmor(p2c, p1c, p2);
                makeArmor(armor, p2c, brutdamage, p1c, p2, p1);
                resetround(p2c, p1c);
            }
        }
