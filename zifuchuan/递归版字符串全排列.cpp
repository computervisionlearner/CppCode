#include<iostream>
using namespace std;


void printstr1(char* p)
{
	while (*p != NULL)
	{
		cout << *p << "  ";
		p++;
	}
	cout << endl;
}

void permutation1(char*a, int size, int n)
{
	if (n == size - 1)
	{
		printstr1(a);
	}
	int dup[256] = { 0 };
	for (int i = n;i < size;i++)
	{
		if (dup[a[i]] == 1)
			continue;
		dup[a[i]] = 1;
		swap(*(a + i), *(a + n));
		permutation1(a, size, n + 1);
		swap(*(a + i), *(a + n));
	}

}



void main()
{
	char str[] = "abbc";
	char*p = str;
	permutation1(p, strlen(p), 0);

	system("pause");
}

/*
void main()
{
	int a[] = { 2,4,7,9,10 };//找出两个数字，相加和为9
	int b[10] = { 0 };
	//cout << sizeof(a) / sizeof(int) << endl;
	for (int i = 0;i < sizeof(a) / sizeof(int);i++)
	{
		int temp = 11 - a[i];
		b[a[i]] = i+1;
		if (b[temp] !=0)
		{
			cout << b[a[i]] << endl;
		
			cout << a[i] << "   "<<a[b[temp]-1] << endl;
			break;
		}
		
	}
	system("pause");

}
*/
