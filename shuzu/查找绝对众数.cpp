#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//给定N个数，出现次数最多的数为众数，
//若某众数出现的次数大于N/2，称该众数为绝对众数

int Mode(int* a, int size)
{
	int count = 0;
	int m = a[0];
	for (int i = 0;i < size;i++)
	{
		if (count == 0)
		{
			m = a[i];
			count = 1;
		}
		else if (m != a[i])
		{
			count--;
		}
		else
		{
			count++;
		}
	}
	return m;
}


void main()
{
	int a[] = { 8,8,1,1,1,8,1,1,6,1,8 };
	int m = Mode(a, sizeof(a) / sizeof(int));

	cout << m << endl;
	system("pause");
}
