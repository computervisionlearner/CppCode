#include <iostream>
#include "vector"
using namespace std;

struct Node
{
	int num;
	Node *pNext;
};

//链表的优缺点：删除插入非常容易，但是查询修改非常麻烦
void printList(Node* p)
{
	Node* px = p;
	cout << "-------" << endl;
	while (px != NULL)
	{
		printf("%d\n", px->num);
		px = px->pNext;
	}
}
void main()
{
	//动态链表的生成
	Node* p;  //头指针

	//创建5个节点指针
	Node *p1, *p2, *p3, *p4, *p5;
	p1 = new Node;
	p2 = new Node;
	p3 = new Node;
	p4 = new Node;
	p5 = new Node;

	p1->num = 1;
	p2->num = 2;
	p3->num = 3;
	p4->num = 4;
	p5->num = 5;

	p = p1;
	p1->pNext = p2;
	p2->pNext = p3;
	p3->pNext = p4;
	p4->pNext = p5;
	p5->pNext = NULL;

	//修改
	for (Node* py = p;py != nullptr;py = py->pNext)
	{
		if (py->num == 3)
		{
			py->num = 30;
		}
	}

	printList(p);
	//删除结点
	p2->pNext = p3->pNext;
	free(p3);
	printList(p);

	//尾部插入
	Node* p6;
	p6 = new Node;
	p6->num = 6;
	p6->pNext = nullptr;
	p5->pNext = p6;

	printList(p);

	//中间插入
	Node* p10;  //插入到2和4之间
	p10 = new Node;
	p10->num = 10;

	p10->pNext = p2->pNext;
	p2->pNext = p10;

	printList(p);

	//printf("%d,%d = %d", p->num, p->pNext->num,(*(p->pNext)).num);
	system("pause");
}
