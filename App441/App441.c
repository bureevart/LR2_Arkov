#include <stdio.h>
#include <omp.h>
#include <time.h>

void main()
{
    long long i, S = 0;
    double T;
    printf("S = %lld\n", S);
    clock_t t;
    t = clock();
    double tt;
    tt = omp_get_wtime();
#pragma omp parallel for reduction(+:S)
    for (i = 0; i < 100000000000; i++) {
        S++;
    }

    t = clock() - t;
    tt = omp_get_wtime() - tt;
    T = (float)t / CLOCKS_PER_SEC;
    printf("S = %lld\n", S);
    printf("T_win = %2.10f c\tTick = %2.10f c\n", T, 1./ (float)CLOCKS_PER_SEC);
    printf("T_omp = %2.10f c\tTick = %2.10f c\n", tt, omp_get_wtick());
}