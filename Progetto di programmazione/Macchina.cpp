#include "Macchina.hpp"
#include "Funzioni.h"
#include "Score.hpp"

macchina::macchina(int mat_m[20][30])
{
    p_x = 15;
    p_y = 18;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            mat_m[i][j] = 0;
        }
    }
}

//IMPOSTA LA FORMA DELLA MACCHINA
void macchina::set_car(int mat_m[20][30])
{
    if ((p_x > 0) && (p_x < 30) && (p_y > 0) && (p_y < 20))
    {
        mat_m[p_y][p_x] = 1;
        mat_m[p_y - 1][p_x - 1] = 2;
        mat_m[p_y + 1][p_x - 1] = 2;
        mat_m[p_y - 1][p_x + 1] = 2;
        mat_m[p_y + 1][p_x + 1] = 2;
    }

}

//DEFINSCE IL CORPO DELLA MACCHINA CHE PUÒ ESSERE COLPITO DAGLI OSTACOLI
int macchina::hit_box(int mat_m[20][30]) 
{

    if (((mat_m[17][p_x - 1] == 8) || (mat_m[17][p_x - 1] == 9)) ||
        ((mat_m[17][p_x + 1] == 8) || (mat_m[17][p_x + 1] == 9)) || //BORDO STRADA
        ((mat_m[17][p_x] == 8) || (mat_m[17][p_x] == 9))) 
    {
        return 4;
    }
    else if (((mat_m[17][p_x - 1] != 0) && (mat_m[17][p_x - 1] != 2)) ||  // IN ALTO A SINISTRA
        ((mat_m[17][p_x + 1] != 0) && (mat_m[17][p_x + 1] != 2)) ||  // IN ALTO A DESTRA 
        ((mat_m[17][p_x] != 0) && (mat_m[17][p_x] != 2)))              // IN ALTO CENTRALE
    {          
        return 1;
    }
    else if (((mat_m[18][p_x - 1] != 0) && (mat_m[18][p_x - 1] != 1)) ||  // CENTRO SINISTRA 
             ((mat_m[18][p_x + 1] != 0) && (mat_m[18][p_x + 1] != 1)))    // CENTRO DESTRA 
    {
        return 2;
    }
    else if (((mat_m[19][p_x + 1] != 0) && (mat_m[19][p_x + 1] != 2)) ||  // IN BASSO A SINISTRA
             ((mat_m[19][p_x - 1] != 0) && (mat_m[19][p_x - 1] != 2)))   // IN BASSO A DESTRA
    {
        return 3;
    }
    else 
        return 0;
}

//GESTISCE LA MODIFICA DELLA POSIZIONE DELLA MACCHINA
void macchina::move()
{
    if (GetAsyncKeyState('A') & 0x0001) p_x -= 3;
    if (GetAsyncKeyState('D') & 0x0001) p_x += 3;
}

//RITORNA LA POSIZIONE DELLA MACCHINA
int macchina::get_x() 
{
    return p_x;
}

//MODIFICA LA POSIZIONE DELLA MACCHINA
void macchina::edit_x(int x) 
{
    p_x = x;
}