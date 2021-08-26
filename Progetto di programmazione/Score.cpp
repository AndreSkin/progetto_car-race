#include "Funzioni.h"
#include "Score.hpp"
#include "Lista_liv_obst.hpp"
#include "Macchina.hpp"
#include "Ostacoli.hpp"

liv_obst liv;

score::score()
{
    score_tot = 0;
    score_liv = 0;
    score_max = 0;
    peso = 5;
    molt = 1;
}

//AUMENTA IL PUNTEGGIO
void score::score_up(bool bonus) {
    peso = 5;
    if (bonus) {
        peso = 20;
    }
    this->score_liv += peso * molt;
    this->score_tot += peso * molt;
    this->score_max += peso * molt;
}

//RIDUCE IL PUNTEGGIO
void score::score_down() {

    peso = 5;
    this->score_liv -= peso * molt;
    this->score_tot -= peso * molt;
}

void score::molt_up(bool up) {
    if (up) {
        molt += 1;
    }
    else {
        molt -= 1;
    }
}

//OTTENI IL PUNTEGGIO DEL LIVELLO 
int score::get_score_liv() {
    return score_liv;
}

//OTTIENI IL PUNTEGGIO TOTTAE DELLA PARTITA
int score::get_score_tot() {
    return score_tot;
}

//OTTENI IL PUNTEGGIO MASSIMO OTTENUTO NELLA PARTITA
int score::get_score_max() {
    return score_max;
}

//RITORNA A ZERO IL PUNTEGGIO DEL LIVELLO
void score::reset_score_liv() {
    score_liv = 0;
}

//STAMPA A SCHERMO IL PUNTEGGIO DEL LIVELLO E QUELLO TOTALE DELLA PARTITA 
void score::draw_score()
{
    gotoxy(56, 3); cout << "           ";
    gotoxy(45, 3); cout << "Score liv: " << score_liv;
    gotoxy(56, 4); cout << "           ";
    gotoxy(45, 4); cout << "Score tot: " << score_tot;
}