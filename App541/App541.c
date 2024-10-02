#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <windows.h>
void main(int argc, char* argv[]) {
	long long N, i, S = 0;
	int TNum, Mask;
	clock_t t;
	double Twin, Tomp;
	N = atoll(argv[1]);
	t = clock();
	Tomp = omp_get_wtime();
#pragma omp parallel for reduction(+:S) private (TNum, Mask)
	for (i = 0; i < N; i++) {
		if (S == 0) {
			TNum = omp_get_thread_num();
			Mask = pow(2, TNum);
			SetThreadAffinityMask(GetCurrentThread(), Mask);
		}
		S++;
	}
	t = clock() - t;
	Tomp = omp_get_wtime() - Tomp;
	Twin = (float)t / CLOCKS_PER_SEC;
	printf("%lld\t%lld\t", N, S);
	printf("%2.10f\t%2.10f\n", Twin, Tomp);
}
