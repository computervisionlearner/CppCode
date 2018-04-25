#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int rotate(int a[N][N])
{
	int layer;
	for (layer = 0; layer<N / 2; layer++)
	{
		int last = N - 1 - layer;
		for (int i = layer; i<last; i++)
		{
			int offset = i - layer;
			int top = a[layer][i];
			a[layer][i] = a[last - offset][layer];
			a[last - offset][layer] = a[last][last - offset];
			a[last][last - offset] = a[i][last];
			a[i][last] = top;
		}
	}

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	time_t times;
	unsigned int seed = time(&times);
	srand(seed);
	int a[N][N];
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			a[i][j] = rand() % 100;
			printf("%4d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n***********************\n");
	rotate(a);

	system("pause");

}
