#include "Funzioni.h"
#include "Lista_liv_obst.hpp"
#include "Ostacoli.hpp"

liv_obst::liv_obst() {
    l = 1;
    LIV = new livello;
    PLIV = LIV;
    PLIV->back = NULL;
    PLIV->next = NULL;
    PLIV->num = l;
    LO = new ostacolo;
    PLIV->suc_obst = LO;
    LO->x = pos_x();
    LO->y = -2;
    LO->id = 6;
    O1 = LO;
    new_ostacolo(19);
    O2 = O1->next;
    O3 = O2->next;
    O4 = O3->next;
}

//DEFINISCE LA POSIZIONE RANDOMICA DI UN OSTACOLO
int liv_obst::pos_x() {
    int m = rand() % 27;
    if (m < 2) {
        return pos_x();
    }
    return m;
}

//DEFINISCE IN MODO RANDOMICO LA FORMA DELL'OSTACOLO
int liv_obst::rand_id() {
    int n = 4;
    if (PLIV->num >= 2 && n != 5) { n++; }
    if (PLIV->num >= 3 && n != 6) { n++; }
    int m = rand() % n;
    if (m < 3) {
        return rand_id();
    }
    return m;
}

//AGGIUNGE ALLA LISTA UN NUOVO ELEMENTO OSTACOLO
void liv_obst::new_ostacolo(int n) {

    for (int i = 0; i < n; i++)
    {
        LO->next = new ostacolo;
        LO->next->x = pos_x();
        LO->next->y = -2;
        LO->next->id = rand_id();
        LO = LO->next;
        LO->next = NULL;
    }
}

//RIPULISCE TUTTA LA LISTA DAGLI OSTACOLI CHE SONO STATI COLPITI
void liv_obst::clear_liv() {
    LO = PLIV->suc_obst;
    l_obst O = LO->next;
    while (O != NULL) {
        if (LO->id == 0) {
            PLIV->suc_obst = O;
            LO = O;
            O = LO->next;
        }
        else if (O->id == 0) {
            LO->next = O->next;
            delete(O);
            O = LO->next;
        }
        else {
            LO = O;
            O = LO->next;
        }
    }
}

//PORTA AVANTI DI LIVELLO
void liv_obst::next_liv() {
    PLIV = PLIV->next;
    LO = PLIV->suc_obst;
    if (O1->y == -2) {
        O1 = LO;
    }
    else if (O2->y == -2) {
        O2 = LO;
    }
    else if (O3->y == -2) {
        O3 = LO;
    }
    else if (O4->y == -2) {
        O4 = LO;
    }
    liv_obst::clear_liv();
}

//CREA UN NUOVO ELEMENTO LIVELLO IN CODA ALLA LISTA
void  liv_obst::new_livello () {

    l++;
    liv_obst::clear_liv();
    PLIV->next = new livello;
    PLIV->next->back = PLIV;
    PLIV = PLIV->next;
    PLIV->next = NULL;
    PLIV->num = l;
    LO = new ostacolo;
    PLIV->suc_obst = LO;
    LO->x = pos_x();
    LO->y = -2;
    LO->id = 6;
    if (O1->y == -2) {
        O1 = LO;
    }
    else if (O2->y == -2) {
        O2 = LO;
    }
    else if (O3->y == -2) {
        O3 = LO;
    }
    else if (O4->y == -2) {
        O4 = LO;
    }
    new_ostacolo(19);
}

//FA TORNARE INDIETRO DI LIVELLO
void liv_obst::liv_down(bool &b) {
    PLIV = PLIV->back;
    LO = PLIV->suc_obst;
    b = true;
    while(LO->next != NULL) {
        LO = LO->next;
    }
}

//RITORNA IL NUMERO DELL LIVELLO
int liv_obst::get_liv() {
    return PLIV->num;
}

//STAMPA A SCHEMRO IL NUMERO DELL LIVELLO CORRENTE
void liv_obst::draw_liv() {
    gotoxy(54, 5); cout << "         ";
    gotoxy(45, 5); cout << "Livello: " << PLIV->num;
}