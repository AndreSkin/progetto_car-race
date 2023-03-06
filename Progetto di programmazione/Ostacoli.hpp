

class ostacoli
{
public:
    ostacoli(int mat_obst[20][30]);
    void draw_part_of_obst(int mat_obst[20][30], int x, int y, int id);
   

};

class form : public ostacoli {
public:
    form(int mat_obst[20][30]);
    void draw_obst(int mat_obst[20][30], int x, int y, int id);

};