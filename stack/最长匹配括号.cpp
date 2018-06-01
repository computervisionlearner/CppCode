#include <iostream>
#include <stack>
using namespace std;
//  如给定字符串   ()()()()()()   则返回12
//  如果给定字符串  (())())      则返回6

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int GetLongestParenthese(const char* p)
{
	int size = (int)strlen(p);
	stack<int> s;
	int answer = 0;
	int start = -1;
	for (int i = 0;i < size;i++)
	{
		if (p[i] == '(')
		{
			s.push(i);
		}
		else
		{
			if (s.empty())
				start = i;
			else
			{
				s.pop();
				if (s.empty())  //到此为止，匹配截止
					answer = max(answer, i - start);
				else               //栈内的都是多余的
					answer = max(answer, i - s.top());
			}
		}
	}
	return answer;
}

void main()
{
	char *p = "((()))()()))";
	int length = GetLongestParenthese(p);
	cout << length << endl;
	
	system("pause");
}
