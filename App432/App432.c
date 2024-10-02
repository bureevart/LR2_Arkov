#include <stdio.h>
#include <omp.h>
#include     <windows.h>

void main()
{
    int TNum, Mask;
    long long i, S = 0;
    printf("S = %lld\n", S);
#pragma omp parallel for reduction(+:S) private (TNum, Mask)
    for (i = 0; i < 1000000000000; i++) {
        if (S == 0) {
            TNum = omp_get_thread_num();
            Mask = pow(2, TNum);
            SetThreadAffinityMask(GetCurrentThread(), Mask);
            printf("TNum = %d\tMask=%d\n", TNum, Mask);
        }
        S++;
    }

    printf("S = %lld\n", S);
}