#include <stdio.h>
#include <assert.h>
struct TreeNode {
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
};

void CreateTree(struct TreeNode** root)
{
	char info = '\0';
	scanf_s("%c", &info, 1);
	if (info == '#') {
		*root = NULL;
	}
	else {
		*root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		assert(*root);
		(*root)->val = info;
		CreateTree(&(*root)->left);
		CreateTree(&(*root)->right);
	}
}

void preOrder(struct TreeNode* root)
{
	if (root) {
		printf("%c ", root->val);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	struct TreeNode* root = NULL;
	CreateTree(&root);
	preOrder(root);
	return 0;
}