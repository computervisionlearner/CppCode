#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<string>


using namespace std;

void Reverse(int* from, int* to)
{
	int t;
	while (from < to)
	{
		t = *from;
		*from = *to;
		*to = t;
		from++;
		to--;
	}
}

bool GetNextPermutation(int* a, int size)
{
	//后找
	int i = size - 2;//从倒数第二个开始
	while ((i >= 0) && (a[i] >= a[i + 1]))
		i--;
	if (i < 0)
	{
		return false;
	}
	//小大
	int j = size - 1;
	while (a[j] <= a[i])
		j--;
	//交换
	swap(a[j], a[i]);
	
	//翻转
	Reverse(a + i + 1, a + size - 1);
	return true;
}

void Print(int* a, int size)
{
	for (int i = 0;i < size;i++)
	{
		cout << a[i] << "  ";
	}
	cout << endl;
}


void main()
{
	int a[] = { 1,2,2,3 };
	int size = sizeof(a) / sizeof(int);
	Print(a, size);
	while (GetNextPermutation(a, size))
	{
		Print(a, size);
	}
		
	system("pause");
}



