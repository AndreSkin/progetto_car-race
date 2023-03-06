#include "Strada.hpp"
#include "Funzioni.h"

strada::strada(int mat_strada[20][30])
{
    for (int i = 0; i < 20; i++) 
    {
        for (int j = 0; j < 30; j++) 
        {
            mat_strada[i][j] = 0;
        }
    }
}

//SVUOTA LO SCHERMO
void strada::reset_map(int mat_strada[20][30])
{
    gotoxy(0, 0);
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            mat_strada[i][j] = 0;
            mat_strada[i][0] = 8;
            mat_strada[i][29] = 9;
        }
    }
}

//STAMPA A VIDEO I DIVERSI CARATTERI IN BASE AL VALORE DELLA MATRICE
void strada::draw_map(int mat_map[20][30]) 
{
    gotoxy(0, 0);

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 30; j++)
        {
            if (mat_map[i][j] == 1)
            {
                cout << "X";
            }
            else if (mat_map[i][j] == 2)
            {
                cout << "o";
            }
            else if (mat_map[i][j] == 3)
            {
                cout << "o";
            }
            else if (mat_map[i][j] == 4)
            {
                cout << "x";
            }
            else if (mat_map[i][j] == 5)
            {
                cout << "Q";
            }
            else if (mat_map[i][j] == 6)
            {
                cout << "B";
            }
            else if (mat_map[i][j] == 8)
            {
                cout << "[";
            }
            else if (mat_map[i][j] == 9)
            {
                cout << "]";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}