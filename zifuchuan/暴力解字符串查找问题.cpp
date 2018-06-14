#include<iostream>
using namespace std;

int BruteForceSearch(const char* s, const char* p)
{
	//在字符串s中查找p第一次出现的位置
	int i = 0, j = 0;
	int size = strlen(p);
	int nlast = strlen(s) - size;
	while ((i < nlast) && (j < size))
	{
		if (s[i + j] == p[j])
		{
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	if (j >= size)
		return i;
	return -1;
}

int BruteForceSearch1(char* s, char* p)
{
	//int i = 0, j = 0;   //i为整个文本的索引，j为待查找的索引
	int size = strlen(p);//待匹配的字符串长度
	int nLast = strlen(s) - size;//需要查询的最大长度

	for (int i = 0;i < nLast;i++)
	{
		for (int j = 0;j < size;j++)
		{
			if (s[i + j] == p[j])
			{
				cout << "当前字符匹配，继续下一个字符" << endl;
			}
			else
			{ 
				break;
			}
			if (j == size - 1)
			{
				return i;
			}
		}
	}
	return -1;
	
}

void main()
{
	char s[] = "aaabcdef";
	char p[] = "abc";
	int idx = BruteForceSearch1(s, p);

	cout << "idx = " << idx << endl;
	system("pause");
}
