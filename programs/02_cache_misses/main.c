#include "mfp_memory_mapped_registers.h"

int a [8][8];

void fill_ij ()
{
    int i, j;

    for (i = 0; i < 8; i ++)
        for (j = 0; j < 8; j ++)
            a [i][j] = i + j;
}

void fill_ji ()
{
    int i, j;

    for (i = 0; i < 8; i ++)
        for (j = 0; j < 8; j ++)
            a [j][i] = i + j;
}

int main ()
{
    int n = 0;
    int i, j;

    // Wait for switch 2

    while ((MFP_SWITCHES & 4) == 0)
        ;

    if (MFP_SWITCHES & 8)
        fill_ij ();
    else
        fill_ji ();

    return 0;
}
