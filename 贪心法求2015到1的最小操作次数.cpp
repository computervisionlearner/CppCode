#include<iostream>
#include<vector>
using namespace std;

int CalcCount(int n)
{
	if (n == 1)
	{
		return 0;
	}
	vector<int> v;
	while (n > 1)
	{
		if (n % 2 == 0)
		{
			n /= 2;
		}
		else
		{
			n--;
		}
		v.push_back(n);
	}
	int length = v.size();
	cout << length << endl;
	for (int i = 0;i < length;i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;
	return length;
}

void main()
{
	int n = 2015;
	int len = CalcCount(n);
	system("pause");
}
