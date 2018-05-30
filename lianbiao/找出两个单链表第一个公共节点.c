#include<iostream>
using namespace std;
//  找出单链表首个公共节点


typedef struct tagSNode
{
	int value;
	tagSNode* pNext;
	tagSNode(int v):value(v),pNext(NULL){}
}SNode;

void createList(SNode* pHead1, SNode* pHead2)
{
	//  第一个链表   1-2-3-5
	//  第二个链表    4-3-5
	SNode* n1 = new SNode(1);
	SNode* n2 = new SNode(2);
	SNode* n3 = new SNode(3);
	SNode* n4 = new SNode(4);
	SNode* n5 = new SNode(5);

	n1->pNext = n2;
	n2->pNext = n3;
	n3->pNext = n5;
	n4->pNext = n3;

	pHead1->pNext = n1;
	pHead2->pNext = n4;

}

int CalcLength(SNode* p)
{
	int length = 0;
	while (p)
	{
		p = p->pNext;
		length++;
	}
	return length;
}
void printList(SNode* pHead)
{
	SNode* temp = pHead;
	cout << "开始打印链表" << endl;
	while (temp != nullptr)
	{
		printf("输入的值为:num = %d,地址为:addr = %p\n", temp->value, temp);
		temp = temp->pNext;
	}
	cout << "打印结束" << endl;
}

SNode* findFirstSameNode(SNode*pA, SNode*pB)
{
	pA = pA->pNext;
	pB = pB->pNext;
	
	int lenA = CalcLength(pA);
	int lenB = CalcLength(pB);
	CalcLength(pA);
	CalcLength(pB);
	printList(pA);
	printList(pB);
	if (lenA > lenB)
	{
		swap(pA, pB);
		swap(lenA, lenB);
	}
	for (int i = 0;i < lenB - lenA;i++)
	{
		pB = pB->pNext;
	}
	while (pA)//起头并进
	{
		if (pA == pB)
			return pA;
		pA = pA->pNext;
		pB = pB->pNext;
	}
	return NULL;
}



void main()
{
	SNode* pHead1 = new SNode(0);
	SNode* pHead2 = new SNode(0);
	createList(pHead1, pHead2);
	printList(pHead1->pNext);
	printList(pHead2->pNext);
	
	SNode *same = findFirstSameNode(pHead1, pHead2);
	if (same == nullptr)
		cout << "未找到公共节点" << endl;
	else
		printf("找到公共节点：节点的值为：%d,地址为：%p", same->value, same);

	system("pause");
}
