#include <iostream>
#include <stack>
using namespace std;


//给定字符串， 仅有() []  {} 六个字符组成
//设计算法判断字符串是否有效 
// 如，()  ()[]是有效的，但是([)] 是无效的
//  栈的实际应用

bool IsLeftParentheses(char c)
{
	return (c == '(') || (c == '[') || (c == '{');
}

bool  IsMatch(char left, char c)
{
	if (left == '(')
		return c == ')';
	if (left == '[')
		return c == ']';
	if (left == '{')
		return c == '}';
	return false;
}

bool MatchParentheses(const char* p)
{
	stack<char> s;
	char cur;
	while (*p)
	{
		cur = *p;
		if (IsLeftParentheses(cur))
			s.push(cur);
		else
		{
			if (s.empty() || !IsMatch(s.top(), cur))
				return false;
			s.pop();
		}
		p++;
	}
	return s.empty();
}

void main()
{
	char* p = "(({})[])[()]";
	bool bMatch = MatchParentheses(p);
	if (bMatch)
		cout << p << "括号匹配" << endl;
	else
		cout << p << "括号不匹配" << endl;
	system("pause");
}
