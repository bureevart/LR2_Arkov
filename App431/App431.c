#include <stdio.h>
#include <omp.h>

void main()
{
    long long i, S = 0;
    printf("S = %lld\n", S);
#pragma omp parallel for reduction(+:S)
    for (i = 0; i < 1000000000000000; i++) 
        S++;
    printf("S = %lld\n", S);
    
}