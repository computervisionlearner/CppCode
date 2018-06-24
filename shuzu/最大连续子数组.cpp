#include<iostream>
using namespace std;

void PrintList(int*p, int from, int to)
{
	for (int i = from;i <= to;i++)
	{
		cout << p[i] << "   ";
	}
	cout << endl;
}
int max(int s1, int s2)
{
	return s1 > s2 ? s1 : s2;
}

int MaxSubarray(int* a, int size, int& from, int& to)
{
	if (!a || size <= 0)
	{
		from = to = -1;
		return 0;
	}
	from = to = 0;
	int s = a[0];
	int result = s;
	int newfrom = 0;
	for (int i = 1;i < size;i++)
	{
		if (s > 0)
		{
			s += a[i];
		}
		else
		{
			s = a[i];
			newfrom = i;
		}
		if (result < s)//更新尾节点
		{
			to = i;
			result = s;
			from = newfrom;
		}
	}

	return result;
}

void main()
{
	int a[] = { 1,-2,3,10,-4,7,2,-5 };
	PrintList(a, 0, sizeof(a) / sizeof(int)-1);
	int from, to;
	int m = MaxSubarray(a, sizeof(a) / sizeof(int), from, to);

	cout << m << endl;
	cout << from << "  " << to << endl;
	PrintList(a, from, to);
	system("pause");
}
