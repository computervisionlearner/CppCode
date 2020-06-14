#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LIS(int* p, int length, int* pre, int& nIdx)
{
	int* longest = new int[length];
	int i, j;
	for (i = 0;i < length;i++)
	{
		longest[i] = 1;
		pre[i] = -1;
	}
	int nLis = 1;
	nIdx = 0;
	for (i = 1;i < length;i++)
	{
		for (j = 0;j < i;j++)
		{
			if(p[j]<=p[i])
			{
				if (longest[i] < longest[j] + 1)
				{
					longest[i] = longest[j] + 1;
					pre[i] = j;
				}
			}
		}
		if (nLis < longest[i])
		{
			nLis = longest[i];
			nIdx = i;
		}
	}
	delete[] longest;
	return nLis;
}

void GetLIS(int* array, int* pre, int nIdx, vector<int>& lis)
{
	while (nIdx >= 0)
	{
		lis.push_back(array[nIdx]);

		nIdx = pre[nIdx];
	}
	reverse(lis.begin(), lis.end());
}

void PrintList(int* p,int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << p[i] << "\t";
	}
	cout << endl;
}

void main()
{
	int array[] = { 1,4,6,2,8,9,7 };
	int size = sizeof(array) / sizeof(int);
	int* pre = new int[size];
	int nIdx;
	int max = LIS(array, size, pre, nIdx);
	cout << "nIdx = " << nIdx << endl;
	PrintList(pre, size);
	vector<int> lis;

	GetLIS(array, pre, nIdx, lis);
	delete[] pre;
	cout << "max = " << max << endl;
	PrintList(&lis.front(), lis.size());

	system("pause");
}
