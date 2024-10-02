#include <stdio.h>
#include <omp.h>

void main()
{
    int i, S = 0;
    printf("ThNum\tS\n");
#pragma omp parallel for
    for (i = 0; i < 10; i++) {
        S++;
        printf("%d\t%d\n", omp_get_thread_num(), S);
    }
}