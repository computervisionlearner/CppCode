#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int Calc(char* str, int size, char from, char to, char aux)
{
	if (size == 0)
	{
		return 0;
	}
	if (str[size - 1] == to)
	{

		int n = Calc(str, size - 1, aux, to, from);
		if (n == -1)
			return -1;
		return (1 << (size - 1)) + n;
	}
	return Calc(str, size - 1, from, aux, to);
}

int main()
{
	char str[] = "AAC";
	cout << Calc(str, 3, 'A', 'C', 'B')<<endl;

	strcpy(str, "ABC");
	cout << Calc(str, 3, 'A', 'C', 'B') << endl;
	system("pause");
	return 0;
}
