

class macchina
{
protected:
    
    int p_x;
    int p_y;

public:

    macchina(int mat_m[20][30]);
    void set_car(int mat_m[20][30]);
    int hit_box(int mat_m[20][30]);
    void move();
    int get_x();
    void edit_x(int x);
};