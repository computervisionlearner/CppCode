#include<iostream>
#include<algorithm>
using namespace std;

int CountLIS(int* a, int length)
{
	int* longest = new int[length]();
	int i, j;
	for (i = 0;i < length;i++)
	{
		longest[i] = 1;//存储以第i个元素结尾的所有序列中，递增子序列的最大长度值
	}
	int result = 1;//存储不连续的最长递增子序列的长度值

	for (i = 1;i < length;i++)
	{

		for (j = 0;j < i;j++)
		{
			if (a[j] <= a[i])
			{
				longest[i] = max(longest[i], longest[j] + 1);
			}			
		}
		
		result = max(result, longest[i]);
	}
	for (int k = 0;k < length;k++)
	{
		cout << longest[k] << "  ";
	}
	cout << endl;
	return result;
}


void main()
{
	int a[] = { 1,0,6,2,8,9,7 };
	int count = CountLIS(a, sizeof(a) / sizeof(int));
	cout << count << endl;
	system("pause");
}
