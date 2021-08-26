#include "Funzioni.h"
#include "Menù.hpp"

int main()
{
    int mat[20][30];

    Hidecurs();

    menù m = menù::menù();
    m.select(mat);

    return 0;

}