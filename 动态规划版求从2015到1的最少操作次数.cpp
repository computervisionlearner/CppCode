#include<iostream>
using namespace std;

int CalcCount(int n, int* pCount, int* pPre)
{
	if (n == 1)
		return 0;
	if (n % 2 == 1)//n为奇数时
	{
		if(pCount[n-1]==0)
			pCount[n - 1] = CalcCount(n - 1, pCount, pPre);
		pPre[n] = n - 1;
		pCount[n] = pCount[n - 1] + 1;
	}
	else
	{
		int n2 = n / 2;
		if(pCount[n2]==0)
			pCount[n2] = CalcCount(n2, pCount, pPre);
		if(pCount[n-1]==0)
			pCount[n - 1] = CalcCount(n - 1, pCount, pPre);

		if (pCount[n2] < pCount[n - 1])
		{
			pPre[n] = n2;
			pCount[n] = pCount[n2] + 1;
		}
		else
		{
			pPre[n] = n - 1;
			pCount[n] = pCount[n - 1] + 1;
		}
	}
	return pCount[n];
}


void main()
{
	int N = 2015;
	int* pCount = new int[N + 1];
	int* pPre = new int[N + 1];


	memset(pCount + 1, 0, sizeof(int)*N);
	memset(pPre + 1, 0, sizeof(int)*N);

	cout << "2015:\t" << CalcCount(N, pCount, pPre) << endl;

	int n = N;
	while (n != 1)
	{
		cout << pPre[n] << " ";
		n = pPre[n];
	}

	cout << endl;
	system("pause");
}
