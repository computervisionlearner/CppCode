#include<iostream>
#include<vector>
using namespace std;

int IsInterlace(char* str1, char* str2, char* str)
{
	int M = strlen(str1);
	int N = strlen(str2);
	int S = strlen(str);
	if (M + N != S)
		return false;
	vector<vector<bool>> p(M + 1, vector<bool>(N + 1));
	int i, j;
	p[0][0] = true;//这么写是为了跟后面的规律一致，
	for (i = 1;i <= M;i++)
		p[i][0] = p[i - 1][0] && (str1[i - 1] == str[i - 1]);
	for (j = 1;j <= N;j++)
		p[0][j] = p[0][j - 1] && (str2[j - 1] == str[j - 1]);
	for (i = 1;i <= M;i++)
	{
		for (j = 1;j <= N;j++)
		{
			p[i][j] = (p[i - 1][j] && (str[i + j - 1] == str1[i - 1])) || 
				(p[i][j - 1] && (str[i + j - 1] == str2[j - 1]));
		}
	}
	return p[M][N];
}

void main()
{
	char s1[] = "aabcc";
	char s2[] = "dbbca";
	char s[] = "aadbbcbcac";
	int result = IsInterlace(s1, s2, s);
	cout << result << endl;
	system("pause");
}
