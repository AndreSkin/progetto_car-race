#pragma once

class men�
{
protected:
	int colore_men�;
	int tasto;
	int sel;

public:

	men�(int col = 9);
	void select(int mat[20][30]);
	void info(int mat[20][30]);
	void exit();
	void load_game(int mat[20][30]);
	void pause(int mat[20][30]);
	void game_over(int max, int mat[20][30]);

};

