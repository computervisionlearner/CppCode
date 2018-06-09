#include<iostream>
using namespace std;

bool IsHuiwen(char *p, int length)
{
	int count = length / 2;
	for (int i = 0;i < count;i++)
	{
		if (p[i] != p[length - 1 - i])
		{
			return false;
		}
	}
	return true;
}

bool IsHuiwen(char *p, int from, int to)
{
	
	while (from < to)
	{
		if (p[from] != p[to])
		{
			return false;
		}
		from++;
		to--;
	}
	return true;
}
void Print(char* a, int i, int j)
{
	for (int n = i;n <= j;n++)
	{
		cout << a[n] << "  ";
	}
	cout << endl;
}
void main()
{
	char *p = new char;
	p = "abdcda";

	for (int i = 0;i < strlen(p);i++)
	{
		for (int j = i;j < strlen(p);j++)
		{
			if (IsHuiwen(p, i, j))
			{
				Print(p, i, j);
			}
		}
	}
	system("pause");

}
