#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <windows.h>
void main(int argc, char* argv[])
{
	long long i, S = 0, Sum = 0;
	double T;
	int p;
	int TNum, Mask;
	p = atoi(argv[1]);
	T = omp_get_wtime();
#pragma omp parallel for reduction(+:S) num_threads(p) private (TNum, Mask)
	for (i = 0; i < 100000000000ll; i++) {
		if (S == 0) {
			TNum = omp_get_thread_num();
			Mask = pow(2, TNum);
			SetThreadAffinityMask(GetCurrentThread(), Mask);
		}
		S++;
		Sum = S + i;
	}
	T = omp_get_wtime() - T;
	printf("%d\t%lld\t%2.10f\t%lld\n", p, S, T, Sum);
}