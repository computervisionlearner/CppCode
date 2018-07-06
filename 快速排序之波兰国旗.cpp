#include<iostream>
#include<algorithm>
using namespace std;

int Partition(int*p, int start, int end, int length)
{
	if (p == nullptr || length <= 0 || start < 0 || end >= length)
	{
		return -1;
	}
	int cur = start; 
	int pivot = p[(start + end) / 2];
	while (cur <= end)
	{
		if (p[cur] > pivot)
		{
			swap(p[cur], p[end]);
			end--;
		}
		else if (p[cur] == pivot)
		{
			cur++;
		}
		else    //小雨中间值的时候
		{
			swap(p[cur], p[start]);
			cur++;
			start++;
		}
	}
	return start;
}


void quick_sort(int* p, int start, int end, int length)
{
	if (start == end)
		return;
	int idx = Partition(p, start, end, length);
	if (idx > start)
	{
		quick_sort(p, start, idx - 1, length);
	}
	if (idx < end)
	{
		quick_sort(p, idx + 1, end, length);
	}
	

}

void main()
{
	int a[] = { 4,3,8,5,9,2,7,1 };
	int size = sizeof(a) / sizeof(int);
	quick_sort(a, 0, size - 1, size);
	//int mid = Partition(a, 0, size - 1, size);
	//cout << mid << endl;
	for (int i = 0;i < size;i++)
	{
		cout << a[i] << "   ";
	}
	system("pause");
}
