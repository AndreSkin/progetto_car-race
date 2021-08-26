#include "Funzioni.h"
#include "Game.hpp"
#include "Menù.hpp"
#include "Strada.hpp"
#include "Macchina.hpp"
#include "Ostacoli.hpp"
#include "Lista_liv_obst.hpp"
#include "Score.hpp"

game::game()
{
    play = true;
}

void game::in_game(int mat[20][30]) {

    system("cls");

    srand(time(0));

    int slowdown = 0; //RALLENTA IL MOVIMENTO DEGLI OSTACOLI
    bool obst2 = false; //
    bool obst3 = false; // IDENTIFICANO SE L'OSTACOLO È PRESENTE
    bool obst4 = false; //
    int dist = 0; // DISTANZA TRA GLI OSTACOLI
    int h = 0; // ALTEZZA IN CUI L'OSTACOLO È STATO COLPITO
    bool back = false; // IDENTIFICA SE BISOGNA TORNARE INDIETRO DI LIVELLO
    int d = 1; // DISTANZA CHE PERCORRONO GLI OSTACOLI OGNI VOLTA CHE AVANZANO
    int speed = 5; //VELOCITÀ DEGLI OSTACOLI

    menù m = menù::menù();
    strada s = strada::strada(mat);
    macchina car = macchina::macchina(mat);
    liv_obst liv = liv_obst::liv_obst();
    ostacoli obst = ostacoli::ostacoli(mat);
    score sc = score::score();
    form fr = form::form(mat);

    while (play)
    {
        //SVUOTA LA MAPPA 
        s.reset_map(mat);

        //DEFINISCE LA POSIZIONE DEGLI OSTACOLI
        fr.draw_obst(mat, liv.O1->x, liv.O1->y, liv.O1->id);
        if (dist == 5 || obst2) {
            if (!obst2) {
                dist = 0;
            }
            fr.draw_obst(mat, liv.O2->x, liv.O2->y, liv.O2->id);
            obst2 = true;
        }
        if (dist == 5 || obst3) {
            if (!obst3) {
                dist = 0;
            }
            fr.draw_obst(mat, liv.O3->x, liv.O3->y, liv.O3->id);
            obst3 = true;
        }
        if (dist == 5 || obst4) {
            if (!obst4) {
                dist = 0;
            }
            fr.draw_obst(mat, liv.O4->x, liv.O4->y, liv.O4->id);
            obst4 = true; 
        }

        //DEFINISCE LA POSIZIONE DELLA MACCHINA
        car.set_car(mat);
        car.move();

        //INDIVIDUA QUALE OSTACOLO è STATO COLPITO
        int p = car.hit_box(mat);
        if (p != 0) {
            if (p == 1) {
                h = 16;
            }
            else if (p == 2) {
                h = 17;
            }
            else if (p == 3) {
                h = 18;
            }
            if (p == 4) {
                sc.score_down();
            }
            else if (liv.O1->y >= h && !liv.O1->colpito) {
                if (liv.O1->id == 6) {
                    sc.score_up(true);
                }
                else {
                    sc.score_down();
                }
                liv.O1->id = 0;
                liv.O1->colpito = true;
            }
            else if (liv.O2->y >= h && !liv.O2->colpito) {
                if (liv.O2->id == 6) {
                    sc.score_up(true);
                }
                else {
                    sc.score_down();
                }
                liv.O2->id = 0;
                liv.O2->colpito = true;
            }
            else if (liv.O3->y >= h && !liv.O3->colpito) {
                if (liv.O3->id == 6) {
                    sc.score_up(true);
                }
                else {
                    sc.score_down();
                }
                liv.O3->id = 0;
                liv.O3->colpito = true;
            }
            else if (liv.O4->y >= h && !liv.O4->colpito) {
                if (liv.O4->id == 6) {
                    sc.score_up(true);
                }
                else {
                    sc.score_down();
                }
                liv.O4->id = 0;
                liv.O4->colpito = true;
            }
            //IN CASO SI COLPISCA IL LIMITE SINISTRO
            if (car.get_x() > 27)
            {
                car.edit_x(26);
            }
            //IN CASO SI COLPISCA IL LIMITE SINISTRO
            if (car.get_x() < 1)
            {
                car.edit_x(2);
            }
            
            liv.new_ostacolo(1);
        }

        //STAMPARE TUTTO SU SCHERMO
        s.draw_map(mat);
        sc.draw_score();
        liv.draw_liv();

        // RITARDO DELLO SPOSTAMENTO DEGLI OSTACOLI PER DARE PIÙ MANEGGEVOLEZZA ALLA MACCHINA 
        slowdown++;
        if (slowdown == speed) {
            //MOVIMENTO DEGLI OSTACOLI
            liv.O1->y = liv.O1->y + d;
            if (obst2) {
                liv.O2->y = liv.O2->y + d;
            }
            if (obst3) {
                liv.O3->y = liv.O3->y + d;
            }
            if (obst4) {
                liv.O4->y = liv.O4->y + d;
            }
            dist++;
            slowdown = 0;

            //NUOVI OSTACOLI
            if (liv.O1->y >= 22) {
                if (!liv.O1->colpito && liv.O1->id != 6) {
                    sc.score_up(false);
                }
                liv.O1->y = -2;
                if (back) {
                    liv.O1 = liv.PLIV->suc_obst;
                    back = false;
                }
                else if (liv.O4->next == NULL) {
                    liv.new_ostacolo(1);
                    liv.O1 = liv.O4->next;
                }
                else {
                    liv.O1 = liv.O4->next;
                }
            }
            else if (liv.O2->y >= 22) {
                if (!liv.O2->colpito && liv.O2->id != 6) {
                    sc.score_up(false);
                }
                liv.O2->y = -2;
                if (back) {
                    liv.O2 = liv.PLIV->suc_obst;
                    back = false;
                }
                else if (liv.O1->next == NULL) {
                    liv.new_ostacolo(1);
                    liv.O2 = liv.O1->next;
                }
                else {
                    liv.O2 = liv.O1->next;
                }
            }
            else if (liv.O3->y >= 22) {

                if (!liv.O3->colpito && liv.O3->id != 6) {
                    sc.score_up(false);
                }
                liv.O3->y = -2;
                if (back) {
                    liv.O3 = liv.PLIV->suc_obst;
                    back = false;
                }
                else if (liv.O2->next == NULL) {
                    liv.new_ostacolo(1);
                    liv.O3 = liv.O2->next;
                }
                else {
                    liv.O3 = liv.O2->next;
                }
            }
            else if (liv.O4->y >= 22) {

                if (!liv.O4->colpito && liv.O4->id != 6) {
                    sc.score_up(false);
                }
                liv.O4->y = -2;
                if (back) {
                    liv.O4 = liv.PLIV->suc_obst;
                    back = false;
                }
                else if (liv.O3->next == NULL) {
                    liv.new_ostacolo(1);
                    liv.O4 = liv.O3->next;
                }
                else {
                    liv.O4 = liv.O3->next;
                }
            }
           
        }

        //NUOVO LIVELLO
        if (sc.get_score_liv() >= 100) {
            if (liv.PLIV->next == NULL) {
                liv.new_livello();
                sc.reset_score_liv();
            }
            else {
                liv.next_liv();
                sc.reset_score_liv();
            }
            if (liv.get_liv() % 10 == 0 && d <= 4) {
                d += 1;
                sc.molt_up(true);
            }
            if (liv.get_liv() % 5 == 0 && speed > 1) {
                speed -= 1;
            }
        }

        //TORNA INDIETRO DI LIVELLO
        if (sc.get_score_liv() < 0 && liv.PLIV->num > 1) {
            liv.liv_down(back);
            sc.reset_score_liv();
            if (liv.get_liv() % 10 == 0) {
                d -= 1;
                sc.molt_up(false);
            }
            if (liv.get_liv() % 5 == 0) {
                speed += 1;
            }
        }
        
        //RICHIAMA IL MENÙ DI PAUSA
        if (GetAsyncKeyState('P') && 0x0001) {
           m.pause(mat);
        }

        //FINE GIOCO 
        if (sc.get_score_tot() < 0 || (sc.get_score_liv() < 0 && liv.PLIV->num == 1)) {
            m.game_over(sc.get_score_max(),mat);
        }
    }
}
