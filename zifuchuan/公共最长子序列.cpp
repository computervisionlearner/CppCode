#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//用动态规划求解LCS问题

int max(int num1, int num2);

void LCS(const char* str1, const char* str2, string &str)
{
	int size1 = (int)strlen(str1);
	int size2 = (int)strlen(str2);
	const char* s1 = str1 - 1;
	const char* s2 = str2 - 1;
	vector<vector<int>> chess(size1+1,vector<int>(size2+1));
	int i, j;
	for (i = 0;i <= size1;i++)
	{
		chess[i][0] = 0;
	}
	for (j = 0;j <= size2;j++)
	{
		chess[0][j] = 0;
	}
	for (i = 1;i <= size1;i++)
	{
		for (j = 1;j <= size2;j++)
		{
			if (s1[i] == s2[i])
				chess[i][j] = chess[i - 1][j - 1] + 1;
			else
				chess[i][j] = max(chess[i][j - 1], chess[i - 1][j]);
		}
	}
	i = size1;
	j = size2;
	while ((i != 0) && (j != 0))
	{
		if (s1[i] == s2[j])
		{
			str.push_back(s1[i]);
			i--;
			j--;
		}
		else
		{
			if (chess[i][j - 1] > chess[i - 1][j])
				j--;
			else
				i--;
		}
	}
	reverse(str.begin(), str.end());
}

void LCS1(const char* str1, const char* str2, string &str)
{
	int size1 = (int)strlen(str1);
	int size2 = (int)strlen(str2);
	const char* s1 = str1 - 1;
	const char* s2 = str2 - 1;
	vector<vector<int>> chess(size1 + 1, vector<int>(size2 + 1));

	for (int i = 0;i <= size1;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (s1[i] == s2[i])
				chess[i][j] = chess[i - 1][j - 1] + 1;
			else
				chess[i][j] = max(chess[i][j - 1], chess[i - 1][j]);
		}
	}

}
int max(int num1, int num2)
{
	if (num1 > num2)
		return num1;
	else
		return num2;
}
void main()
{
	const char* str1 = "tcggatcgactt";
	const char* str2 = "agcctacgta";
	string str;
	LCS(str1, str2, str);
	cout << str.c_str() << endl;
	system("pause");
}

void main1()
{
	string str = "abcde.fg";
	string str1 = "";

	int idx = str.find(".", 0);
	for (int i = 0;i < idx;i++)
	{
		str1 += str[i];
	}
	cout << str1 << endl;
	system("pause");


}

