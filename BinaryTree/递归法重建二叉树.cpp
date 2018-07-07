#include<iostream>
#include<cstdio>


#include <exception>
using namespace std;


struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
	int* startInorder, int* endInorder)
{
	int rootValue = startPreorder[0];//先找到根节点
	BinaryTreeNode* root = new BinaryTreeNode();
	root->value = rootValue;
	root->left = root->right = nullptr;

	if (startPreorder == endPreorder)
	{
		if (startInorder == endInorder&&  *startPreorder == *startInorder)
			return root;
		else
			throw exception("invalid input");
	}
	//在中序遍历中找到根节点的值
	int* rootInorder = startInorder;
	while (rootInorder <= endInorder&& *rootInorder != rootValue)
		++rootInorder;
	if (rootInorder == endInorder&&*rootInorder != rootValue)
		throw exception("invalid input.");
	int leftLength = rootInorder - startInorder;
	int* leftPreorderEnd = startPreorder + leftLength;
	if (leftLength > 0)
	{
		//构建左子树
		root->left = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
	}
	if (leftLength < endPreorder - startPreorder)
	{
		//构建右子树
		root->right = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
	}
	return root;
}

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
	if (preorder == nullptr || inorder == nullptr || length <= 0)
	{
		return nullptr;
	}
	return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

void PrintTreeNode(const BinaryTreeNode* pNode)
{
	if (pNode != nullptr)
	{
		printf("value of this node is: %d\n", pNode->value);
		if (pNode->left != nullptr)
			printf("value of its left child is: %d.\n", pNode->left->value);
		else
			printf("left child is nullptr.\n");
		if (pNode->right != nullptr)
			printf("value of its right child is: %d.\n", pNode->right->value);
		else
			printf("right child is nullptr.\n");
	}
	else
	{
		printf("this node is nullptr.\n");
	}
	printf("\n");
}

void PrintTree(const BinaryTreeNode* pRoot)
{
	PrintTreeNode(pRoot);
	if (pRoot != nullptr)
	{
		if (pRoot->left != nullptr)
			PrintTree(pRoot->left);
		if (pRoot->right != nullptr)
			PrintTree(pRoot->right);
	}
}

void DestroyTree(BinaryTreeNode* pRoot)
{
	if (pRoot != nullptr)
	{
		BinaryTreeNode* pLeft = pRoot->left;
		BinaryTreeNode* pRight = pRoot->right;
		delete pRoot;
		pRoot = nullptr;
		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}

void Test(char* testName, int* preorder, int* inorder, int length)
{
	if (testName != nullptr)
		printf("%s begins:\n", testName);
	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", preorder[i]);
	printf("\n");
	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", inorder[i]);
	printf("\n");
	try
	{
		BinaryTreeNode* root = Construct(preorder, inorder, length);
		PrintTree(root);	
		DestroyTree(root);
	}
	catch (std::exception& exception)
	{
		printf("Invalid Input.\n");
	}
}

void main()
{
	const int length = 7;
	int preorder[] = { 1, 2, 4, 5, 3, 6, 7 };
	int inorder[] = { 4, 2, 5, 1, 6, 3, 7 };
	Test("Test1", preorder, inorder, length);
	system("pause");
}
