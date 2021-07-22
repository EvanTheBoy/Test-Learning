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

	//判断是不是度为2的结点
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

	//线索化遍历二叉树
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

	//寻找当前结点的直接后继结点
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

	//删除某个数据
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
		if (replacement) {   //度为1的结点
			replacement->parent = node->parent;
			if (!node->parent) {  //度为1的根结点
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
		else if (!node->parent) {  //度为0的根结点
			root = NULL;
		}
		else {  //度为0的叶子结点
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
	//判断是否包含某个元素
	bool contains(int e)
	{
		if (getNode(e) != NULL) {
			return true;
		}
		return false;
	}

	//得到当前二叉搜索树的大小
	int getSize()
	{
		return size;
	}

	//添加数据
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

	//删除某个数据
	void remove(int val)
	{
		removeNode(getNode(val));
	}

	//中序遍历二叉搜索树
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
	printf("现在存储的数据是:\n");
	bst.order();
	cout << endl;
	cout << "存储数据的大小:" << bst.getSize() << " " << endl;
	printf("现在是否存在元素10:\n");
	if (bst.contains(10)) {
		cout << "存在元素10" << endl;
	}
	else {
		cout << "不存在元素10" << endl;
	}
	printf("现在删除元素10:");
	bst.remove(10);
	cout << endl;
	bst.order();
	cout << endl;
	printf("现在是否存在元素10:\n");
	if (bst.contains(10)) {
		cout << "存在元素10" << endl;
	}
	else {
		cout << "不存在元素10" << endl;
	}
	cout << "二叉搜索树的大小:" << bst.getSize() << " " << endl;
	printf("现在删除元素7:\n");
	bst.remove(7);
	bst.order();
	cout << endl;
	cout << "二叉搜索树的大小:" << bst.getSize() << " " << endl;
	printf("现在添加元素20:\n");
	bst.add(20);
	bst.order();
	cout << endl;
	printf("现在添加元素1:\n");
	bst.add(1);
	bst.order();
	cout << endl;
	printf("现在添加元素12:\n");
	bst.add(12);
	bst.order();
	cout << endl;
	cout << "最终二叉树的大小为:" << bst.getSize() << endl;
	end = clock();
	long time = (end - start) / CLOCKS_PER_SEC;
	printf("一共所花时间:%ld秒", time);
	return 0;
}