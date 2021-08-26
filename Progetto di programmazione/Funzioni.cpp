#include "Funzioni.h"

//NASCONDE IL PUNTATORE 
void Hidecurs()
{
    _CONSOLE_CURSOR_INFO CurInfo;

    CurInfo.dwSize = 1;
    CurInfo.bVisible = false;

    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

//PERMETTE LO SPOSTAMENTO DEL PUNTATORE IN UNA POSIZIONE DESIDERATA
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//MODIFICA IL COLORE DEI CARATTERI NEL TERMINALE
void colora(int cod)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cod);
}