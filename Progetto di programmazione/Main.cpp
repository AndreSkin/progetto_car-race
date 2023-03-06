#include "Funzioni.h"
#include "Menu.hpp"

int main()
{
    int mat[20][30];

    Hidecurs();

    menu m = menu();
    m.select(mat);

    return 0;
}