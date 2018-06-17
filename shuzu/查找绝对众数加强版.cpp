#include<iostream>
#include<vector>

using namespace std;
//查找三分之N的绝对众数

void FindMode(int* a, int size, vector<int>&mode)
{
	int m, n;
	int cm = 0, cn = 0;
	for (int i = 0;i < size;i++)
	{
		if (cm == 0)
		{
			m = a[i], cm = 1;
		}
		else if (cn == 0)
		{
			n = a[i], cn = 1;
		}
		else if (a[i] == m)
		{
			cm++;
		}
		else if (a[i] == n)
		{
			cn++;
		}
		else
		{
			cm--, cn--;
		}
	}
	cm = 0, cn = 0;//验证是否大于三分之N
	for (int i = 0;i < size;i++)
	{
		if (a[i] == m)
		{
			cm++;
		}
		else if (a[i] == n)
		{
			cn++;
		}
	}
	if (cm > size / 3)
	{
		mode.push_back(m);
	}
	if (cn > size / 3)
	{
		mode.push_back(n);
	}
}

void main()
{
	int a[] = { 1,2,3,4,5,2,2,3,3,2,3 };
	vector<int> mode;
	FindMode(a, sizeof(a) / sizeof(int), mode);
	for (int i = 0;i < mode.size();i++)
	{
		cout << mode[i] << "  ";
	}
	system("pause");
}
