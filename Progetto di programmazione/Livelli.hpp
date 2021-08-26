#pragma once

class livelli
{
public:

    struct ostacolo 
    {
        int id;
        int x;
        int y;
        bool colpito = false;
        ostacolo* next;
    };

    typedef ostacolo* l_obst;

    l_obst LO;

    int pos_x();
    void fill(int n);
    void new_ostacolo();

    struct livello {
        int num;
        int n_obst;
        l_obst suc_obst;
        livello* next;
        livello* back;
    };

    typedef livello* l_liv;

    l_liv LIV;
    l_liv PLIV;

    livelli();
    void new_livello(int l);
    int get_n_liv();

};