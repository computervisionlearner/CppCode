#include<iostream>
using namespace std;


int Find(int* array, int size, int a)
{
	int from = 0;
	int to = size - 1;
	int mid;
	bool find = false;
	while (from < to)
	{
		mid = (from + to) / 2;
		if (array[mid] == a)
		{
			find = true;
			break;
		}
		if (array[mid] > a)
		{
			to = mid - 1;
		}
		else
		{
			from = mid + 1;
		}
	}
	if (find)
	{
		return mid;
	}
	else
	{
		return -1;
	}
}

void Reverse(int* array, int from, int to)
{
	int temp;
	while (from < to)
	{
		temp = array[from];
		array[from] = array[to];
		array[to] = temp;
		from++;
		to--;
	}
}

void main()
{
	int a[] = { 1,2,3,4,5,6,7 };
	//Reverse(a, 0, 6);
	//cout << a << endl;
	cout << Find(a, sizeof(a) / sizeof(int), 4) << endl;
	system("pause");
}
