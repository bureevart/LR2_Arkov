﻿#include <stdio.h>
#include <omp.h>

void main()
{
    int Np;
    Np = omp_get_num_procs();
    printf("Number of processors = %d\n", Np);
}