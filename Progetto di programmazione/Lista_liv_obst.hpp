#pragma once

class liv_obst {
protected:

    int l;

public:
    struct ostacolo {
        int id;
        int x;
        int y;
        bool colpito = false;
        ostacolo* next;
    };

    typedef ostacolo* l_obst;

    l_obst LO;
    l_obst O1;
    l_obst O2;
    l_obst O3;
    l_obst O4;


    int pos_x();
    int rand_id();
    void new_ostacolo(int n);

    struct livello {
        int num;
        l_obst suc_obst;
        livello* next;
        livello* back;
    };

    typedef livello* l_liv;

    l_liv LIV;
    l_liv PLIV;

    liv_obst();
    void clear_liv();
    void next_liv();
    void new_livello();
    void liv_down(bool &b);
    int get_liv();
    void draw_liv();
};