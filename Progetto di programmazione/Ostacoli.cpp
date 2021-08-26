#include "Funzioni.h"
#include "Lista_liv_obst.hpp"
#include "Ostacoli.hpp"


ostacoli::ostacoli(int  mat_obst[20][30]){
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            mat_obst[i][j] = 0;
        }
    }
}

//IMPOSTA IL TIPO DI CARATTERE DA INSERIRE NELLA POSIZIONE DESIDERATA
void ostacoli::draw_part_of_obst(int mat_obst[20][30], int x, int y, int id) {
    if (x > 0 && x < 30 && y > 0 && y < 20) {
        mat_obst[y][x] = id;
    }
}

form::form(int mat_obst[20][30]) : ostacoli::ostacoli(mat_obst){

}

//GESTISCE IL TIPO DI OSTACOLO CHE SI DESIDERA E LA SUA FORMA 
void form::draw_obst(int mat_obst[20][30], int x, int y, int id) {
    if (id == 3) { // OSTACOLO MACCHINA 
        ostacoli::draw_part_of_obst(mat_obst, x - 1, y - 1, id); ostacoli::draw_part_of_obst(mat_obst, x + 1, y - 1, id);
        ostacoli::draw_part_of_obst(mat_obst, x, y, id);
        ostacoli::draw_part_of_obst(mat_obst, x - 1, y + 1, id); ostacoli::draw_part_of_obst(mat_obst, x + 1, y + 1, id);
    }
    else if (id == 4) {  // OSTACOLO STRISCIA CHIODATA
        ostacoli::draw_part_of_obst(mat_obst, x - 3, y, id); 
        ostacoli::draw_part_of_obst(mat_obst, x - 2, y , id); 
        ostacoli::draw_part_of_obst(mat_obst, x - 1, y, id);
        ostacoli::draw_part_of_obst(mat_obst, x , y, id); 
        ostacoli::draw_part_of_obst(mat_obst, x + 1, y, id);
        ostacoli::draw_part_of_obst(mat_obst, x + 2 , y , id);
        ostacoli::draw_part_of_obst(mat_obst, x + 3, y, id);
    }
    else if (id == 5) {  // OSTACOLO BUCA 
        ostacoli::draw_part_of_obst(mat_obst, x, y, id);
        ostacoli::draw_part_of_obst(mat_obst, x, y + 1, id);
        ostacoli::draw_part_of_obst(mat_obst, x + 1, y, id);
        ostacoli::draw_part_of_obst(mat_obst, x + 1, y + 1, id);
    }
    else if (id == 6) {
        ostacoli::draw_part_of_obst(mat_obst, x, y, id);
    }
    else if (id == 0) { // OSTACOLO VUOTO
        ostacoli::draw_part_of_obst(mat_obst, x, y, id);
    }
}