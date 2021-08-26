#pragma once

#include <iostream>
#include <Ctime>
#include <Conio.h>
#include <windows.h>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


using namespace std;

void Hidecurs(); //NASCONDE IL CURSORE NEL TERMINALE
void gotoxy(int x, int y); //SPOSTA UN OGGETTO ALLE COORDINATE (x,y)
void colora(int cod); //COLORA UN OGGETTO DEL COLORE CORRISPONDENTE A cod