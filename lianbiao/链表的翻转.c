#include <stdio.h>
#include <tchar.h>
#include <iostream>
using namespace std;

typedef struct tagSNode
{
	int value;
	tagSNode* pNext;
	tagSNode(int v) :value(v), pNext(NULL) {}
}SNode;

void reverse(SNode* pHead, int from, int to)
{
	SNode* pCur = pHead->pNext;
	int i;
	for (i = 0;i < from - 1;i++)
	{
		pHead = pCur;
		pCur = pCur->pNext;
	}
	SNode* pPre = pCur;
	pCur = pCur->pNext;
	to--;
	SNode* pNext;
	for (;i < to;i++)
	{
		pNext = pCur->pNext;
		pCur->pNext = pHead->pNext;
		pHead->pNext = pCur;
		pPre->pNext = pNext;
		pCur = pNext;
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

int _tmain(int argc, _TCHAR* argv[])
{
	SNode* pHead = new SNode(0);
	int i;
	for (i = 0;i < 10;i++)
	{
		SNode* p = new SNode(rand()%10);
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	
	Print(pHead);

	reverse(pHead, 4, 8);
	Print(pHead);
	destory(pHead);
	system("pause");
	return 0;
}
