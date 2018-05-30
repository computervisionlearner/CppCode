#include<iostream>
#include<queue>
using namespace std;

const int N = 16;
int calc(int G[N][N])
{
	int step[N];
	int stepNumber[N];
	memset(step, 0, sizeof(int)*N);
	memset(stepNumber, 0, sizeof(int)*N);

	stepNumber[0] = 1;
	queue<int> q;
	q.push(0);
	int from, i, s;
	while (!q.empty())
	{
		from = q.front();
		q.pop();
		s = step[from] + 1;
		for (i = 1;i < N;i++)
		{
			if (G[from][i] == 1)//连通
			{
				//i尚未可达或发现更短的路
				if (step[i] == 0 || (step[i] > s))
				{
					step[i] = s;
					stepNumber[i] = stepNumber[from];
					q.push(i);
				}
				else if (step[i] == s)
				{
					stepNumber[i] += stepNumber[from];
				}


			}
		}
	}
	return stepNumber[N - 1];
}

int main()
{
	int G[N][N];
	memset(G, 0, sizeof(int)*N*N);//数组的初始化
	G[0][1] = G[0][4] = 1;
	G[1][5] = G[1][0] = G[1][2] = 1;
	G[2][1] = G[2][6] = G[2][3] = 1;
	G[3][2] = G[3][7] = 1;
	G[4][0] = G[4][5] = 1;
	G[5][1] = G[5][4] = G[5][6] = G[5][9] = 1;
	G[6][2] = G[6][5] = G[6][7] = G[6][10] = 1;
	G[7][3] = G[7][6] = 1;
	G[8][9] = G[8][12] = 1;
	G[9][8] = G[9][13] = G[9][10] = 1;
	G[10][9] = G[10][14] = G[10][11] = 1;
	G[11][10] = G[11][15] = 1;
	G[12][8] = G[12][13] = 1;
	G[13][9] = G[13][12] = G[13][14] = 1;
	G[14][10] = G[14][13] = G[14][15] = 1;
	G[15][11] = G[15][14] = 1;
	cout << calc(G) << endl;
	system("pause");
	return 0;
}
