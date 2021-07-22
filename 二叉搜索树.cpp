#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <ctime>
using namespace std;
struct TreeNode {
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;
	int val;
};

TreeNode* CreateNode(int val, TreeNode* parent)
{
	TreeNode* newNode = new TreeNode;
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = parent;
	return newNode;
}

class BinarySearchTree {
private:
	int size = 0;
	TreeNode* root;

	//�ж��ǲ��Ƕ�Ϊ2�Ľ��
	bool hasTwoChildren(TreeNode* node)
	{
		if (node->left && node->right) {
			return true;
		}
		return false;
	}

	int compare(int e1, int e2)
	{
		return (e1 - e2);
	}

	TreeNode* getNode(int val)
	{
		TreeNode* node = root;
		while (node != NULL)
		{
			int cmp = compare(val, node->val);
			if (cmp == 0) {
				return node;
			}
			else if (cmp > 0) {
				node = node->right;
			}
			else {
				node = node->left;
			}
		}
		return NULL;
	}

	//����������������
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

	//Ѱ�ҵ�ǰ����ֱ�Ӻ�̽��
	TreeNode* successor(TreeNode* node)
	{
		if (!node) {
			return NULL;
		}
		TreeNode* cur = node->right;
		if (cur) {
			while (cur->left)
			{
				cur = cur->left;
			}
			return cur;
		}
		while (node->parent && node == node->parent->right)
		{
			node = node->parent;
		}
		return node->parent;
	}

	//ɾ��ĳ������
	void removeNode(TreeNode* node)
	{
		if (!node) {
			return;
		}
		if (hasTwoChildren(node)) {
			TreeNode* succ = successor(node);
			node->val = succ->val;
			node = succ;
		}
		TreeNode* replacement = node->left ? node->left : node->right;
		if (replacement) {   //��Ϊ1�Ľ��
			replacement->parent = node->parent;
			if (!node->parent) {  //��Ϊ1�ĸ����
				root = replacement;
				delete(node);
			}
			else if (node == node->parent->left) {
				node->parent->left = replacement;
				delete(node);
			}
			else {
				node->parent->right = replacement;
				delete(node);
			}
		}
		else if (!node->parent) {  //��Ϊ0�ĸ����
			root = NULL;
		}
		else {  //��Ϊ0��Ҷ�ӽ��
			if (node->parent->left == node) {
				node->parent->left = NULL;
				delete(node);
			}
			else {
				node->parent->right = NULL;
				delete(node);
			}
		}
		--size;
	}

public:
	//�ж��Ƿ����ĳ��Ԫ��
	bool contains(int e)
	{
		if (getNode(e) != NULL) {
			return true;
		}
		return false;
	}

	//�õ���ǰ�����������Ĵ�С
	int getSize()
	{
		return size;
	}

	//�������
	void add(int val)
	{
		if (!root) {
			root = CreateNode(val, NULL);
			++size;
			return;
		}
		TreeNode* node = root;
		TreeNode* parent = root;
		int cmp = 0;
		while (node)
		{
			cmp = compare(val, node->val);
			parent = node;
			if (cmp > 0) {
				node = node->right;
			}
			else if (cmp < 0) {
				node = node->left;
			}
			else {
				return;
			}
		}
		TreeNode* newNode = CreateNode(val, parent);
		if (cmp > 0) {
			parent->right = newNode;
		}
		else {
			parent->left = newNode;
		}
		++size;
	}

	//ɾ��ĳ������
	void remove(int val)
	{
		removeNode(getNode(val));
	}

	//�����������������
	void order()
	{
		MorrisMid(root);
	}
};

int main()
{
	clock_t start, end;
	start = clock();
	BinarySearchTree bst;
	bst.add(7);
	bst.add(10);
	bst.add(3);
	bst.add(15);
	bst.add(5);
	bst.add(8);
	printf("���ڴ洢��������:\n");
	bst.order();
	cout << endl;
	cout << "�洢���ݵĴ�С:" << bst.getSize() << " " << endl;
	printf("�����Ƿ����Ԫ��10:\n");
	if (bst.contains(10)) {
		cout << "����Ԫ��10" << endl;
	}
	else {
		cout << "������Ԫ��10" << endl;
	}
	printf("����ɾ��Ԫ��10:");
	bst.remove(10);
	cout << endl;
	bst.order();
	cout << endl;
	printf("�����Ƿ����Ԫ��10:\n");
	if (bst.contains(10)) {
		cout << "����Ԫ��10" << endl;
	}
	else {
		cout << "������Ԫ��10" << endl;
	}
	cout << "�����������Ĵ�С:" << bst.getSize() << " " << endl;
	printf("����ɾ��Ԫ��7:\n");
	bst.remove(7);
	bst.order();
	cout << endl;
	cout << "�����������Ĵ�С:" << bst.getSize() << " " << endl;
	printf("�������Ԫ��20:\n");
	bst.add(20);
	bst.order();
	cout << endl;
	printf("�������Ԫ��1:\n");
	bst.add(1);
	bst.order();
	cout << endl;
	printf("�������Ԫ��12:\n");
	bst.add(12);
	bst.order();
	cout << endl;
	cout << "���ն������Ĵ�СΪ:" << bst.getSize() << endl;
	end = clock();
	long time = (end - start) / CLOCKS_PER_SEC;
	printf("һ������ʱ��:%ld��", time);
	return 0;
}