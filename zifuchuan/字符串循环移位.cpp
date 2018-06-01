#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

void ReverseString(char* s, int from, int to)
{
	int count = (to - from + 1) / 2;
	while (count--)
	{
		char temp = s[from];
		s[from++] = s[to];
		s[to--] = temp;
	}
}

void recurent(char* str, int k)
{
	//int length = k%(strlen(str)-1);
	ReverseString(str, 0, k - 1);
	ReverseString(str, k , strlen(str)-1);
	ReverseString(str, 0, strlen(str) - 1);
}
void main1()
{
	char p[] = "abcdefghijk";
	recurent(p, 3);
	cout << p << endl;
	system("pause");
}

void main()
{
	char str1[] = "i love c++";
	vector<int> count;
	int len = strlen(str1);
	for (int i = 0;i < len;i++)
	{
		if (str1[i] == ' ')
			count.push_back(i);
	}
	ReverseString(str1, 0, count[0]-1);
	cout << str1 << endl;
	ReverseString(str1, count[0]+1, count[1] - 1);
	cout << str1 << endl;
	ReverseString(str1, count[1]+1, strlen(str1) - 1);
	cout << str1 << endl;
	ReverseString(str1, 0, strlen(str1)-1);
	cout << str1 << endl;
	system("pause");
}
