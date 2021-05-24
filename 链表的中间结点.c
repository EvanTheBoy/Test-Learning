#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node* CreateList()
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}

struct Node* CreateNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int ListLength(struct Node* headNode)
{
	int len = 0;
	while (headNode)
	{
		headNode = headNode->next;
		len++;
	}
	return len;
}

void InsertNode(struct Node* headNode, int index, int data)
{
	if (!headNode || index <= 0 || index > ListLength(headNode)) {
		return -1;
	}
	else if (index == 1) {
		struct Node* newNode = CreateNode(data);
		newNode->next = headNode->next;
		headNode->next = newNode;
	}
	else {
		struct Node* temp = headNode;
		for (int i = 0; i < index - 1; i++) {
			temp = temp->next;
		}
		struct Node* newNode = CreateNode(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void PrintList(struct Node* headNode)
{
	struct Node* pMove = headNode->next;
	while (pMove)
	{
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

void MiddleDataOfList(struct Node* headNode)  //输出中间结点的数据
{
	struct Node* posNode = headNode;
	int i, len;
	if (!headNode) {
		return -1;
	}
	len = ListLength(headNode) / 2;
	for (i = 0; i < len; i++) {
		posNode = posNode->next;
	}
	printf("中间结点的数据是：%d\n", posNode->data);
}

int main()
{
	int i, pos, data, k;
	struct Node* pl = CreateList();
	while (1)
	{
		printf("1.往链表中输入数据；2.打印链表；3.打印中间结点；4.退出：");
		scanf("%d", &i);
		if (i == 1) {
			printf("请输入你想要添加的位置：");
			scanf("%d", &pos);
			printf("请输入你想要添加的数据：");
			scanf("%d", &data);
			InsertNode(pl, pos, data);
		}
		else if (i == 2) {
			printf("链表为：\n");
			PrintList(pl);
		}
		else if (i == 3) {
			MiddleDataOfList(pl);
		}
		else if (i == 4) {
			break;
		}
	}
	return 0;
}