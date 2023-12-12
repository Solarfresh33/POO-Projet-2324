#include "Jeu.hpp"

int main(){
    MBuf buf;
    std::cout.rdbuf(&buf);
    Heros h("Heros", 100, 100, 10);
    vilain v("vilain", 100, 100, 10);
    h.afficher();
    v.afficher();
    h.attaquer(v);
    v.attaquer(h);
    h.afficher();
    v.afficher();
    return 0;
}