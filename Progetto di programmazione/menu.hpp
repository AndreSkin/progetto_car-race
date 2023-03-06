class menu
{
protected:
	int colore_menu;
	int tasto;
	int sel;

public:

	menu(int col = 9);
	void select(int mat[20][30]);
	void info(int mat[20][30]);
	void exit();
	void load_game(int mat[20][30]);
	void pause(int mat[20][30]);
	void game_over(int max, int mat[20][30]);
};