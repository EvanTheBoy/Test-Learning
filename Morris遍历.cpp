#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	char val;
};

TreeNode* CreateNode(char val)
{
	TreeNode* newNode = new TreeNode;
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void CreateTree(TreeNode* parent, TreeNode* left, TreeNode* right)
{
	parent->left = left;
	parent->right = right;
}

//先序遍历
void MorrisPre(TreeNode* cur)
{
	if (!cur) {
		return;
	}
	TreeNode* mostRight = NULL;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight) {
			while (mostRight->right && mostRight->right != cur)
			{
				mostRight = mostRight->right;
			}
			if (!mostRight->right) {
				mostRight->right = cur;
				cout << cur->val << " ";
				cur = cur->left;
				continue;
			}
			else {
				mostRight->right = NULL;
			}
		}
		else {
			cout << cur->val << " ";
		}
		cur = cur->right;
	}
}

//中序遍历
void MorrisMid(TreeNode* cur)
{
	if (!cur) {
		return;
	}
	TreeNode* mostRight = NULL;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight) {
			while (mostRight->right && mostRight->right != cur)
			{
				mostRight = mostRight->right;
			}
			if (!mostRight->right) {
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				cout << cur->val << " ";
				mostRight->right = NULL;
			}
		}
		else {
			cout << cur->val << " ";
		}
		cur = cur->right;
	}
}

//反转链表
TreeNode* reverse(TreeNode* head)
{
	TreeNode* cur = head;
	TreeNode* pre = NULL;
	TreeNode* next;
	while (cur)
	{
		next = cur->right;
		cur->right = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

void printNode(TreeNode* head)
{
	TreeNode* tail = reverse(head);
	while (tail)
	{
		cout << tail->val << " ";
		tail = tail->right;
	}
	reverse(tail); //为了不破坏二叉树的结构，打印完毕后必须反转回来
}

//后序遍历
void MorrisLast(TreeNode* cur)
{
	if (!cur) {
		return;
	}
	TreeNode* root = cur;
	TreeNode* mostRight = NULL;
	while (cur)
	{
		mostRight = cur->left;
		if (mostRight) {
			while (mostRight->right && mostRight->right != cur)
			{
				mostRight = mostRight->right;
			}
			if (!mostRight->right) {
				mostRight->right = cur;
				cur = cur->left;
				continue;
			}
			else {
				mostRight->right = NULL;
				printNode(cur->left);
			}
		}
		cur = cur->right;
	}
	printNode(root);
}

int main()
{
	TreeNode* node1 = CreateNode('A');
	TreeNode* node2 = CreateNode('B');
	TreeNode* node3 = CreateNode('C');
	TreeNode* node4 = CreateNode('D');
	TreeNode* node5 = CreateNode('E');
	TreeNode* node6 = CreateNode('F');
	TreeNode* node7 = CreateNode('G');
	TreeNode* node8 = CreateNode('H');
	TreeNode* node9 = CreateNode('I');
	TreeNode* node10 = CreateNode('J');
	TreeNode* node11 = CreateNode('K');
	TreeNode* node12 = CreateNode('L');
	TreeNode* node13 = CreateNode('M');
	CreateTree(node1, node2, node3);
	CreateTree(node2, node4, node5);
	CreateTree(node3, node6, node7);
	CreateTree(node4, node9, node10);
	CreateTree(node5, NULL, NULL);
	CreateTree(node6, NULL, NULL);
	CreateTree(node7, node8, node11);
	CreateTree(node8, node12, node13);
	CreateTree(node9, NULL, NULL);
	CreateTree(node10, NULL, NULL);
	CreateTree(node11, NULL, NULL);
	CreateTree(node12, NULL, NULL);
	CreateTree(node13, NULL, NULL);
	printf("先序遍历:");
	MorrisPre(node1);
	cout << endl;
	printf("中序遍历:");
	MorrisMid(node1);
	cout << endl;
	printf("后序遍历:");
	MorrisLast(node1);
	return 0;
}