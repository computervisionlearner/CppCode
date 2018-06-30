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

int main()
{
	//第一个13号是星期六；注意题目条件，有的需要判断输入是否异常
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
	system("pause");
}
