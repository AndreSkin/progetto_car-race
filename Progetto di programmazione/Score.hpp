

class score {
protected:

	int score_tot;
	int score_liv;
	int score_max;
	int peso;
	int molt;

public:

	score();
	void score_up(bool bonus);
	void score_down();
	void molt_up(bool up);
	int get_score_liv();
	int get_score_tot();
	int get_score_max();
	void reset_score_liv();
	void draw_score();
};