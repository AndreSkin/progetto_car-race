#include "Funzioni.h"
#include "Men�.hpp"

int main()
{
    int mat[20][30];

    Hidecurs();

    men� m = men�::men�();
    m.select(mat);

    return 0;

}