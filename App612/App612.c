#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <windows.h>
void main(int argc, char* argv[])
{
	long long i, N;
	double T;
	double dx, x = 0.0, S = 0.0;
	N = atoll(argv[1]);
	T = omp_get_wtime();
	dx = 30.0 / N;
	for (i = 0; i < N; i++) {
		x = -10.0 + (i + 0.5) * dx;
		S = S + 0.06 * x * x * x + 0.3 * x * x - 8.0 * x + 110.0;
	}
	S = S * dx;
	T = omp_get_wtime() - T;
	printf("%lld\t%2.10f\t%2.10f\n", N, S, T);
}
