#include "Funzioni.h"
#include "Livelli.hpp"
#include "Ostacoli.hpp"

livelli::livelli() {
    LIV = new livello;
    PLIV = LIV;
    PLIV->num = 1;
    PLIV->back = NULL;
    PLIV->next = NULL;
    LO = new ostacolo;
    PLIV->suc_obst = LO;
    LO->x = pos_x();
    LO->y = 2;
    LO->id = rand() % 10;
}

int livelli::pos_x() {
    int m = rand() % 27;
    if (m < 2) {
        m = 3;
    }
    return m;
}

void livelli::fill(int n) {
  
    srand(time(0));
    LO = new ostacolo;
    PLIV->suc_obst = LO;
    LO->x = pos_x();
    LO->y = 2;
    LO->id = rand() % 10;
}

void livelli::new_ostacolo() {

    srand(time(0));
    LO->next = new ostacolo;
    LO->next->x = pos_x();
    LO->next->y = 2;
    LO->next->id = rand() % 10;
    LO = LO->next;
    LO->next = NULL;
}

void  livelli::new_livello(int l) {
    PLIV->next = new livello;
    PLIV->next->back = PLIV;
    PLIV = PLIV->next;
    PLIV->num = l;
    PLIV->next = NULL;
}

int livelli::get_n_liv() {
    return PLIV->num;
}