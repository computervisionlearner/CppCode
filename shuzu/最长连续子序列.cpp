#include<iostream>

using namespace std;

int MaxSequence(int* a, int size, int& from, int& to)
{
	from = to = 0;
	int p = 1;//存储当前值为止的最长子序列长度
	int result = p;//存储所有情况下，最长子序列长度
	int newfrom = 0;
	for (int i = 1;i < size;i++)
	{
		if (a[i] - a[i - 1] == 1)//满足条件时候
		{
			p++;
		}
		else
		{
			p = 1;
			newfrom = i;
		}
		if (result < p)
		{
			result = p;
			from = newfrom;
			to = i;
		}
	}
	return result;
}

void PrintList(int* a, int from, int to)
{
	for (int i = from;i <= to;i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}

void main()
{
	int a[] = { 1,2,3,34,56,57,58,59,60,61,99,121 };
	int from, to;
	int length = MaxSequence(a, sizeof(a) / sizeof(int), from, to);

	cout << "最长子序列长度为：" << length << endl;
	cout << "最长子序列为：";
	PrintList(a, from, to);
	system("pause");
}
