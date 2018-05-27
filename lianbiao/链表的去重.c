#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
//只是去重，保留一个曾经重复的数字
typedef struct tagSNode
{
	int value;
	tagSNode* pNext;
	tagSNode(int v) :value(v), pNext(NULL) {}
}SNode;

void deletDuplicateNode(SNode* pHead)
{
	SNode* pPre = pHead->pNext;
	SNode* pCur;
	while (pPre)
	{
		pCur = pPre->pNext;
		if (pCur && (pCur->value == pPre->value))
		{
			pPre->pNext = pCur->pNext;
			delete pCur;
		}
		else
		{
			pPre = pCur;
		}
	}
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

int _tmain1(int argc, _TCHAR* argv[])
{
	SNode* pHead = new SNode(0);
	int data[] = { 2,3,3,5,7,8,8,8,9,9,30 };
	int size = sizeof(data) / sizeof(int);
	for (int i = size - 1;i >= 0;i--)
	{
		SNode* p = new SNode(data[i]);
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	Print(pHead);
	deletDuplicateNode(pHead);
	Print(pHead);
	destory(pHead);
	system("pause");
	return 0;
}
