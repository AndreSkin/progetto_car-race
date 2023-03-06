#include "menu.hpp"
#include "Funzioni.h"
#include "Game.hpp"

menu::menu(int col)
{
	colore_menu = col;
	tasto = 0;
	sel = 1;
}

//DEFINISCE LA SCHERMATA DELLE INFORMAZIONI SUL GIOCO
void menu::info(int mat[20][30])
{
	int tasto = 0;
	system("cls");
	while (tasto != 27)
	{
		colora(15);
		gotoxy(3, 1); cout << "INFO";
		gotoxy(3, 2); cout << "=====================================================================";

		colora(colore_menu);
		gotoxy(3, 4); cout << "MOVIMENTO";
		colora(15);
		gotoxy(3, 5); cout << "DESTRA ----> =  D";
		gotoxy(3, 6); cout << "SINISTRA <---- =  A";

		gotoxy(3, 8); cout << "=====================================================================";

		colora(colore_menu);
		gotoxy(3, 10); cout << "OSTACOLI";
		colora(15);
		gotoxy(3, 11); cout << "O"; gotoxy(5, 11); cout << "O";
		gotoxy(4, 12); cout << "O"; gotoxy(7, 12); cout << "= VEICOLO";
		gotoxy(3, 13); cout << "O";  gotoxy(5, 13); cout << "O";

		gotoxy(3, 15); cout << "XXXXXXX = STRISCIA CHIODATA";

		gotoxy(35, 11); cout << "[    ]";
		gotoxy(35, 12); cout << "[    ] = BORDO STRADA";
		gotoxy(35, 13); cout << "[    ]";

		gotoxy(37, 15); cout << "\\";
		gotoxy(37, 16); cout << "\\ = BUCA";

		gotoxy(3, 18); cout << "B = BONUS";

		gotoxy(3, 20); cout << "=====================================================================";

		colora(colore_menu);
		gotoxy(3, 22); cout << "PUNTEGGIO";
		colora(15);
		gotoxy(3, 23); cout << "SORPASSARE UN'OSTACOLO = +5";
		gotoxy(3, 24); cout << "SCONTRARSI CON L'OSTACOLO BONUS = + 20";
		gotoxy(3, 25); cout << "SCONTRARSI CON UN OSTACOLO O IL BORDO STRADA = -5";

		colora(colore_menu);
		gotoxy(3, 27); cout << "PREMERE 'ESC' PER TORNARE AL MENU";

		tasto = _getch();

	}

	menu::select(mat);
}


//DEFINISCE LA SCHERMA DI CHIUSURA DEL GIOCO
void menu::exit()
{
	system("cls");
	colora(colore_menu);
	gotoxy(3, 3); cout << " __    ___   ___   __        __       ___ ";
	gotoxy(3, 4); cout << "/  \\  |  |  |  |  |  \\      |  \\ \\ / |";
	gotoxy(3, 5); cout << "| __  |  |  |  |  |  |      |--<  V  |--- ";
	gotoxy(3, 6); cout << "\\__/  |__|  |__|  |__/      |__/  |  |___";
	colora(15);
	Sleep(2000);
	gotoxy(0, 20);
	std::exit(0);
}

//DEFINISCE LA SCHERMATA DI CARICAMENTO DEL GIOCO
void menu::load_game(int mat[20][30])
{
	system("cls");
	int in_x = 10;
	int var = 0;
	int load = 0;
	int load_x = 10;
	int slowdown = 1;

	colora(colore_menu);
	gotoxy(23, 2); cout << "      __      _      __               __        __      _      _    _    ___     ";
	gotoxy(23, 3); cout << "|    |  |    / \\    |  \\   |  |\\  |  /  \\      /  \\    / \\    | \\  / |  | ";
	gotoxy(23, 4); cout << "|    |  |   /---\\   |   |  |  | \\ |  | __      | __   /---\\   |  \\/  |  |--- ";
	gotoxy(23, 5); cout << "|__  |__|  /     \\  |__/   |  |  \\|  \\__/      \\__/  /     \\  |      |  |___";
	colora(15);

	gotoxy(9, 13); cout << " _____________________________________________________________________________________________________ ";
	gotoxy(9, 14); cout << "/                                                                                                     \\";
	gotoxy(9, 15); cout << "|                                                                                                     |";
	gotoxy(9, 16); cout << "\\_____________________________________________________________________________________________________/";

	//PERMETTE IL MOVIMENTO DELLA MACCHININA E L'AVANZAMENTO DELLA BARRA DI CARICAMENTO
	while (load != 100) {

		Sleep(30);

		if (load <= 100 && slowdown == 0) {
			gotoxy(60, 11); cout << load << "%";
			load++;

			gotoxy(load_x, 15); cout << "|";
			load_x++;

			slowdown = 2;
		}

		gotoxy(in_x, 20); cout << "                          ";
		gotoxy(in_x, 21); cout << "                          ";
		gotoxy(in_x, 22); cout << "                          ";
		gotoxy(in_x, 23); cout << "                          ";
		gotoxy(in_x, 24); cout << "                          ";
		if (in_x > 93) {
			in_x = 0;
		}
		in_x++;
		if (var >= 0 && var <= 2) {
			gotoxy(in_x, 21); cout << "    _-_-";
			gotoxy(in_x, 22); cout << "_-_-__  ";
			gotoxy(in_x, 23); cout << "   _-_- ";
		}
		else {
			gotoxy(in_x, 21); cout << "    -_-_";
			gotoxy(in_x, 22); cout << "-_-_--  ";
			gotoxy(in_x, 23); cout << "   -_-_ ";
		}
		var++;
		if (var == 5) {
			var = 0;
		}
		gotoxy(in_x + 9, 20); cout << "   _______";
		gotoxy(in_x + 9, 21); cout << " _/\\______\\__";
		gotoxy(in_x + 9, 22); cout << "/ ,-. -|-  ,-.`-.";
		gotoxy(in_x + 9, 23); cout << "`( o )----( o )-'";
		gotoxy(in_x + 9, 24); cout << "  `-'      `-'";

		slowdown--;
	}
	game g;
	g.in_game(mat);
}

//DEFINISCE IL menu PRINCIPALE 
void menu::select(int mat[20][30])
{
	system("cls");
	tasto = 0;
	while (tasto != 13)
	{
		//DEFINISCE IL CORMPO DEL menu
		gotoxy(3, 2); colora(15); cout << "CAR GAME";
		gotoxy(3, 3); cout << "==============";

		gotoxy(3, 4); colora(15); if (sel == 1) { colora(colore_menu); } cout << "START GAME";

		gotoxy(3, 5); colora(15); if (sel == 2) { colora(colore_menu); } cout << "INFO";

		gotoxy(3, 6); colora(15); if (sel == 3) { colora(colore_menu); } cout << "EXIT";

		gotoxy(3, 10); colora(15); cout << "PREMERE 'INVIO' PER SELEZIONARE";

		//GESTISCE L'OPZIONE DA SCEGLIERE 
		tasto = _getch();
		if (tasto == 's' || tasto == 'S') { sel++; }
		else if (tasto == 'w' || tasto == 'W') { sel--; }
		if (sel == 4) { sel = 1; }
		if (sel == 0) { sel = 3; }
	}

	//FA INIZIARE UN NUOVA PARTITA
	if (sel == 1)
	{
		menu::load_game(mat);

	}

	//MOSTRA LE INFORMAZIONI DA SAPERE SUL GIOCO 
	else if (sel == 2)
	{
		menu::info(mat);
	}

	//FA USCIRE DAL GIOCO
	else if (sel == 3)
	{
		menu::exit();
	}
}

//DEFINIZIONE DEL CORPO DELLA PAUSA
void menu::pause(int mat[20][30]) {
	int sel = 1;
	int tasto = 0;

	while (tasto != 13) {

		//IMPOSTA IL CONTORNO DEL menu DI PAUSA 
		colora(15);
		for (int i = 9; i <= 16; i++)
		{
			for (int j = 9; j <= 14; j++)
			{
				gotoxy(i, j); cout << " ";
				gotoxy(8, j); cout << "|";
				if (i > 8) { gotoxy(i, 8); cout << "_"; }
				gotoxy(i, 14); cout << "_";
				gotoxy(17, j); cout << "|";
			}
		}

		//IMPOSTA LE OPZIONI DEL menu DI PAUSA 
		gotoxy(10, 10); colora(15); cout << "PAUSE";
		gotoxy(10, 11); colora(15); cout << "=======";
		gotoxy(10, 12); colora(15); if (sel == 1) { colora(9); }cout << "RESUME";
		gotoxy(10, 13); colora(15); if (sel == 2) { colora(9); }cout << "MENU'";

		//GESTISCE L'OPZIONE DA SCEGLIERE 
		tasto = _getch();
		if (tasto == 's' || tasto == 'S') { sel++; }
		else if (tasto == 'w' || tasto == 'W') { sel--; }
		if (sel == 3) { sel = 1; }
		if (sel == 0) { sel = 2; }
	}
	//FA RITORNARE AL menu INIZIALE
	if (sel == 2) {
		
		menu::select(mat);
	}
}

//DEFINIZIONE DEL CORPO DEL PARTITA PERSA 
void menu::game_over(int max, int mat[20][30]) {

	//STAMPA A SCHERMO LA SCRITTA "GAME OVER"
	system("cls");
	colora(9);
	gotoxy(3, 3); cout << " __      _      _    _    ___       __            ___   __";
	gotoxy(3, 4); cout << "/  \\    / \\    | \\  / |  |         |  |  \\    /  |     | _|";
	gotoxy(3, 5); cout << "| __   /---\\   |  \\/  |  |---      |  |   \\  /   |---  |\\  ";
	gotoxy(3, 6); cout << "\\__/  /     \\  |      |  |___      |__|    \\/    |___  | \\";
	colora(15);

	int tasto = 0;
	int sel = 1;

	while (tasto != 13) {

		//MOSTRA IL PUNTEGGIO MASSIMO OTTENUTO
		gotoxy(3, 10); colora(9); cout << "MAX SCORE :"; colora(15); cout << max;

		//IMPOSTA LE OPZIONI DEL menu DI SCONFITTA
		gotoxy(3, 12); colora(15); if (sel == 1) { colora(9); }cout << "RETRY";
		gotoxy(3, 13); colora(15); if (sel == 2) { colora(9); }cout << "MENU'";

		//GESTISCE L'OPZIONE DA SCEGLIERE 
		tasto = _getch();
		if (tasto == 's' || tasto == 'S') { sel++; }
		else if (tasto == 'w' || tasto == 'W') { sel--; }
		if (sel == 3) { sel = 1; }
		if (sel == 0) { sel = 2; }
	}

	//FA COMINCIARE UNA NUOVA PARTITA
	if (sel == 1) {
		game g;
		g.in_game(mat);
	}

	//FA RITORNARE AL menu INIZIALE
	if (sel == 2) {
		menu::select(mat);
	}
}