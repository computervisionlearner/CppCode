#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s)
{
	int startIdx = 0;
	int endIdx = 0;

	//保存最大回文子串的起始位置和终止位置
	int resStart = 0;
	int resEnd = 0;
	int maxLen = 0;
	int countLen = 0;

	for (int i = 0;i < s.size();i++)
	{
		//回文串为奇数串的处理
		startIdx = i;
		endIdx = i;
		countLen = 0;
		while (startIdx >= 0 && endIdx < s.size())
		{
			if (s[startIdx] == s[endIdx])
			{
				if (startIdx == endIdx)//刚开始重合的情况
				{
					countLen++;
				}
				else
				{
					countLen += 2;
				}
				startIdx--;
				endIdx++;
			}
			else
			{
				break;
			}
		}

		if (countLen > maxLen)
		{
			maxLen = countLen;
			resStart = startIdx + 1;
			resEnd = endIdx - 1;
		}
		//回文子串为偶数串处理

		startIdx = i ;
		endIdx = i + 1;
		countLen = 0;
		while (startIdx >= 0 && endIdx < s.size())
		{
			if (s[startIdx] == s[endIdx])
			{
				countLen += 2;
				startIdx--;
				endIdx++;
			}
			else
			{
				break;
			}
		}
		//当前回文子串大于上一次回文串
		if (countLen > maxLen)
		{
			maxLen = countLen;
			resStart = startIdx + 1;
			resEnd = endIdx - 1;
		}

	}
	
	return s.substr(resStart, resEnd - resStart + 1);
}

void main()
{
	string s = "12212321";
	cout << longestPalindrome(s) << endl;
	system("pause");
}
