#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node* CreateList()  //创建链表
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}

struct Node* CreateNode(int data)   //创建结点
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int ListLength(struct Node* headNode)  //获取链表长度
{
	int len = 0;
	while (headNode)
	{
		headNode = headNode->next;
		len++;
	}
	return len;
}

void InsertNode(struct Node* headNode, int index, int data)  //在指定位置插入节点
{
	if (!headNode || index <= 0 || index > ListLength(headNode)) {  //未找到返回-1
		return -1;
	}
	else if (index == 1) {   //单独考虑第一个位置的插入情况
		struct Node* newNode = CreateNode(data);
		newNode->next = headNode->next;
		headNode->next = newNode;
	}
	else {
		struct Node* temp = headNode;
		for (int i = 0; i < index - 1; i++) {   //控制temp指针一直移动
			temp = temp->next;
		}
		struct Node* newNode = CreateNode(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void ReverseList(struct Node* headNode)  //反转链表函数
{
	struct Node* pCur, * prev, * pNext;  //需要三个工作指针
	if (headNode == NULL || headNode->next == NULL) {
		return headNode;
	}
	prev = NULL;  //第一个指针设为NULL
	pCur = headNode->next;  //pCur指向第一个有数据的结点，为当前指针
	pNext = headNode->next->next;  //pNext指向第二个有数据的结点
	while (1)
	{
		pCur->next = prev;   //改变当前指针指向的数据的指向，即指向空
		if (pNext == NULL) {
			break;
		}
		prev = pCur;  //prev向前移动一位
		pCur = pNext;  //pCur向前移动一位
		pNext = pNext->next;  //pNext也向前移动一位
	}
	headNode->next = pCur;  //最后需要改变头结点的指向
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

int main()
{
	struct Node* pl = CreateList();
	int i, data, pos;
	while (1)
	{
		printf("1.往链表中输入数据；2.打印链表；3.打印反转链表；4.退出：");
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
			printf("反转后的链表为：\n");
			ReverseList(pl);
			PrintList(pl);
		}
		else if (i == 4) {
			break;
		}
	}
	return 0;
}