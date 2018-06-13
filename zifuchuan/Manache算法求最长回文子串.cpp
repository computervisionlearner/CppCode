#include<iostream>
#include<vector>
#include<string>
using namespace std;

int min(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}

string preProcess(string s)
{
	string s1 = "^";
	for (int i = 0;i < s.length();i++)
	{
		s1 += "#" + s.substr(i, 1);
	}
	s1 += "#";
	return s1;
}

void Manacher(string raw_s)
{
	string s = preProcess(raw_s);
	int *p = new int(s.length());
	p[0] = 1;
	int id = 0;
	int mx = 1;

	for (int i = 1;i < s.length();i++)
	{
		//p[i] = (mx > i) ? min(mx - i, p[2 * id - 1]) : 1;
		if (mx > i)
		{
			p[i] = min(p[2 * id - i], mx - i);
		}
		else
		{
			p[i] = 1;
		}

		for (;(s[i + p[i]] == s[i - p[i]]);p[i]++);
		if (i + p[i] > mx)
		{
			id = i;
			mx = i + p[i];
		}
	}
	int maxLen = 0, center_idx = 0;
	for (int i = 1;i < s.length();i++)
	{
		if (p[i] > maxLen)
		{
			maxLen = p[i];
			center_idx = i;
		}
	}
	for (int i = 0;i < s.length();i++)
	{
		cout << p[i] << "  ";
	}
	cout << endl;
	cout << raw_s.substr((center_idx - maxLen) / 2, maxLen - 1) << endl;
}

void main()
{
	string s = "12212321";
	Manacher(s);
	system("pause");
}
