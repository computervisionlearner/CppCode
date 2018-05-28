#include <iostream>
#include "vector"
using namespace std;

//作为静态数组，无法边长，一旦分配，就固定了不可以增加
//外部的内存可以访问，但是外部内存可能被使用，也可能没有被使用
//没有使用的情况下，越界偶尔会成功，但还是可能被再次回收利用
//已经使用，必然失败


//动态数组的   查询/修改   与静态数组是一样的  这里不做赘述

void printList(int *p, int length)
{
	for (int i = 0;i < length;i++)
	{
		printf("%4d", p[i]);
	}
	cout << endl;
}

//动态数组的删除  也非常麻烦
void main删除()
{
	int *p = (int *)malloc(sizeof(int) * 10);
	for (int i = 0;i < 10;i++)
	{
		p[i] = i;
		printf("%d\n", p[i]);
	}
	int length = 10;
	int num = 3;//要删除的数据

	if (num == p[length - 1])  //如果要删除的是最后一个
	{
		length--;
	}
	//如果要删除的不是最后一个
	for (int i = 0;i < length - 1;i++)
	{
		if (p[i] == num)
		{
			for (int j = i;j < length - 1;j++)
			{
				p[j] = p[j + 1];
			}
			length--;
		}
	}
	printList(p, length);
	system("pause");
}


//动态数组的增加 插入到尾部
void main插入到尾部()
{

	int *p = (int *)malloc(sizeof(int) * 10);
	for (int i = 0;i < 10;i++)
	{
		p[i] = i;
		printf("%d\n", p[i]);
	}
	//数组的拓展
	//动态数组拓展  , realloc 重新分配内存

	//插入到尾部
	int length = 10;
	int num = 10;//要插入的元素
	int *px = (int*)realloc(p, sizeof(int)*(length + 1));//重新分配内存

	px[10] = num;
	cout << "变长以后的数组" << endl;
	printList(px, ++length);

	system("pause");
}

//动态数组中间插入  每次需要重新分配内存，非常消耗计算机资源
void main()
{

	int *p = (int *)malloc(sizeof(int) * 10);
	for (int i = 0;i < 10;i++)
	{
		p[i] = i;
		printf("%d\n", p[i]);
	}
	//数组的拓展
	//动态数组拓展  , realloc 重新分配内存

	
	int length = 10;

	//插入到中间
	int wei = 4;//当数组某个元素等于这个值，就插入

	int num = 10;//要插入的元素
	int *px = (int*)realloc(p, sizeof(int)*(length + 1));//重新分配内存
	length++;
	printList(px, length-1);
	for (int i = 0;i < length - 1;i++)
	{
		if (px[i] == wei)
		{
			for (int j = length - 1;j > i;j--)
			{
				px[j] = px[j - 1];//往后移动
			}
			px[i] = num;//插入
			break;
		}
	}
	cout << "变长以后的数组" << endl;
	printList(px, length);

	system("pause");
}
