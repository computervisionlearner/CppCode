#include<iostream>
using namespace std;

int get_days(int y, int m)
{
	int i;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		return 31;
	}
	else if (m == 2)
	{
		if (i == 1)
			return 29;
		else return 28;
	}
	return 30;
}

int count()
{
	//第一个13号是星期六
	//这个函数是用于计算13号分布在星期几。。
	int n, a[7] = { 0 }, week = 6; 
	cin >> n;

	for (int i = 1900;i <= 1900 + n - 1;i++)
	{
		for (int j = 1;j <= 12;j++)
		{
			a[week % 7]++;
			week += get_days(i, j);
		}
	}

	for (int k = 0;k < 7;k++)
	{
		cout << a[k] << "  ";
	}
	cout << endl;
	return 0;
}

int count1()
{
	//这个函数是计算从1900~1900+n-1年中，所有星期五是哪一号的数量

	int a[32] = { 0 };
	int N;
	cin >> N;
	int days;
	int end = 0;
	for (int year = 1900;year <= 1900 + N - 1;year++)
	{		
		for (int month = 1;month <= 12;month++)
		{
			days = get_days(year, month);			
			int weeks;
			for (int k = 1;k <= days;k++)
			{
				weeks = (end + k) % 7;
				if (weeks == 5)
				{
					a[k]++;
				}
			}
			end = weeks;
		}
	}
	cout << a[13] << endl;
	return 0;
}


void main()
{
	count();
	count1();
	system("pause");
}
