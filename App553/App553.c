#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <windows.h>
void main(int argc, char* argv[])
{
	long long i, S = 0, Sum = 0;
	double T;
	int p;
	p = atoi(argv[1]);
	T = omp_get_wtime();
#pragma omp parallel for reduction(+:S) num_threads(p)
	for (i = 0; i < 100000000000ll; i++) {
		S++;
		Sum = S + i;
	}
	T = omp_get_wtime() - T;
	printf("%d\t%lld\t%2.10f\t%lld\n", p, S, T, Sum);
}
