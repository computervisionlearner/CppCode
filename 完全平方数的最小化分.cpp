#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

void SquareCut(int N, int* pre, int* minCut)
{
	for (int i = 1;i <= N;i++)
	{
		int sqrtnum = sqrt(i);
		if (pow(sqrtnum, 2) == i)
		{
			minCut[i] = 1;
			pre[i] = 0;
			continue;
		}
		minCut[i] = i;//先初始化为i
		pre[i] = i - 1;
		for (int j = 1;j <= sqrtnum;j++)
		{
			int temp = i - j*j;
			if (minCut[i] > minCut[temp] + 1)//存最小值
			{
				minCut[i] = minCut[temp] + 1;
				pre[i] = temp;
			}
		}
	}
}

void Print(int a, int* pre, vector<int>& v1)
{

	while (a != 0)
	{
		v1.push_back(sqrt(a - pre[a]));
		cout << a - pre[a] << " -- " << sqrt(a - pre[a]) << "   ";
		a = pre[a];		
	}
	cout << endl;
}

void main()
{
	long int N = 201314;
	int* pre = new int[N + 1];
	int* minCut = new int[N + 1];
	vector<int> v1;
	SquareCut(N, pre, minCut);
	Print(N, pre, v1);
	cout << N << "  = ";
	for (int i = 0;i < v1.size();i++)
	{

		cout << v1[i] << "^2  ";
	}
	delete[] pre;
	delete[] minCut; 
	system("pause");
}

