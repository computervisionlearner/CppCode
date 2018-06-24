#include<iostream>
#include<algorithm>
using namespace std;

void PrintList(int* a, int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << a[i] << "   ";
	}
	cout << endl;
}

void PrintList(int*p, int from, int to)
{
	for (int i = from;i <= to;i++)
	{
		cout << p[i] << "   ";
	}
	cout << endl;
}

void sort(int* p, int* idx, int size)
{
	for (int i = 0;i < size - 1;i++)
	{
		for (int j = 0;j < size - 1 - i;j++)
		{
			if (p[j] > p[j + 1])
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;

				int temp1 = idx[j];
				idx[j] = idx[j + 1];
				idx[j + 1] = temp1;
			}
		}
	}
}
int MinSubarray(int* a, int size, int& from, int& to)
{
	int* sum = new int[size];
	int* idx = new int[size];
	
	sum[0] = a[0];
	
	int i;
	for (i = 0;i < size;i++)
	{
		idx[i] = i;
	}
	for (i = 1;i < size;i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	sort(sum, idx, size);
	int diff = abs(sum[0]);
	int result = diff;

	for (i = 1;i < size;i++)
	{
		diff = sum[i] - sum[i - 1];

		if (result > diff)
		{
			from = idx[i - 1] + 1;
			to = idx[i];
			result = diff;
		}
	}
	delete[] sum;
	delete[] idx;
	return result;
}


void main()
{
	int a[] = { 1,-2,3,10,-4,7,2,-5 };
	cout << "原始数组为";
	PrintList(a, sizeof(a) / sizeof(int));
	int from, to;
	int result = MinSubarray(a, sizeof(a) / sizeof(int), from, to);
	
	cout << "最小子数组的和为：" << result << endl;
	cout << "最接近0的连续子数组为：" ;
	PrintList(a, from, to);
	system("pause");
}
