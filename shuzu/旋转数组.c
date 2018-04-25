#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4

int rotate1(int a[N][N])  //顺时针旋转90°
{
	printf("\n**********顺时针旋转*************\n");
	for (int i = 0; i<N / 2; i++)
	{
		
		for (int j = i; j<N - 1 - i; j++)
		{
			int temp = a[i][j];
			a[i][j] = a[N-1-j][i];
			a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = temp;
		}
	}


	return a;

}

int rotate(int a[N][N])//逆时针旋转90°
{
	printf("\n*********逆时针旋转************\n");
	for (int i = 0; i<N / 2; i++)
	{
		for (int j = i; j<N-1-i; j++)
		{
			int temp = a[i][j];
			a[i][j] = a[j][N - 1 - i];
			a[j][N - 1 - i] = a[N - 1 - i][N - 1 - j];
			a[N - 1 - i][N - 1 - j] = a[N - 1 - j][i];
			a[N - 1 - j][i] = temp;
		}
	}

	return a;

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
	

	int *mat = rotate(a);
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			printf("%4d", *mat++);
		}
		printf("\n");
	}
	system("pause");

}
