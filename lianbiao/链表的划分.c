#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include "vector"
using namespace std;
//  链表的划分   如：1-7-4-3-9   给定一个值5，则变成 1-4-3-7-9
typedef struct tagSNode
{
	int value;
	tagSNode* pNext;
	tagSNode(int v) :value(v), pNext(NULL) {}
}SNode;

void Partition(SNode* pHead, int pivotKey)
{
	//两个链表的头指针
	SNode* pLeftHead = new SNode(0);
	SNode* pRightHead = new SNode(0);

	//两个链表的当前最后一个元素

	SNode* left = pLeftHead;
	SNode* right = pRightHead;
	SNode* p = pHead->pNext;
	while (p)
	{
		if (p->value < pivotKey)
		{
			left->pNext = p;
			left = p;
		}
		else
		{
			right->pNext = p;
			right = p;
		}
		p = p->pNext;
	}
	left->pNext = pRightHead->pNext;
	right->pNext = NULL;
	pHead->pNext = pLeftHead->pNext;
	delete pLeftHead;
	delete pRightHead;

}

void Print(SNode *head)
{

	SNode *tmp;

	tmp = head;

	printf("链表打印开始!!!\n");
	while (tmp != NULL)
	{
		printf("输入的值为:num = %d,地址为:addr = %d\n", tmp->value, tmp);
		tmp = tmp->pNext;
	}
	printf("链表打印结束!!!\n");
}

void destory(SNode *p)
{
	SNode* next;
	while (p)
	{
		next = p->pNext;
		delete p;
		p = next;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	SNode* pHead = new SNode(0);
	pHead->pNext = NULL;
	for (int i = 0;i < 10;i++)
	{
		SNode* p = new SNode(rand() % 100);
		p->pNext = pHead->pNext;	
		pHead->pNext = p;
	}
	Print(pHead);
	Partition(pHead, 50);
	Print(pHead);
	destory(pHead);
	system("pause");

	
	return 0;
}
