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
	struct Node* p = headNode;
	int count = 0;
	while (p != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

void InsertNode(struct Node* headNode, int position, int data)  //往通讯录中插入数据
{
	if (!headNode || position <= 0 || position > ListLength(headNode)) {

		return;
	}
	struct Node* newNode = CreateNode(data);
	struct Node* pMove = headNode;
	int i = 0;
	if (position == 1) {
		newNode->next = headNode->next;
		headNode->next = newNode;
	}
	else {
		while (i < position - 1)
		{
			i++;
			pMove = pMove->next;
		}
		newNode->next = pMove->next;
		pMove->next = newNode;
	}
}

void DeleteNode(struct Node* headNode, int data)  //删除某个结点
{
	if (!headNode || headNode->next == NULL) {
		return;
	}
	struct Node* pMove = headNode->next;
	struct Node* prev = headNode;
	if (pMove->data == data) {
		headNode->next = pMove->next;
		free(pMove);
	}
	else {
		while (pMove->data != data)
		{
			prev = prev->next;
			pMove = pMove->next;
		}
		prev->next = pMove->next;
		free(pMove);
	}
}

int IndexOfNode(struct Node* headNode, int data)  //查询
{
	if (!headNode) {
		return;
	}
	struct Node* pMove = headNode->next;
	int index = 1;
	while (pMove->data != data)
	{
		pMove = pMove->next;
		index++;
		if (pMove == NULL) {  //没有找到查询的数据就令index直接为-1，方便后面的判断
			index = -1;
			break;  //然后记得这里要退出循环，否则会引起读取访问权限冲突
		}
	}
	return index;
}

void PrintList(struct Node* headNode)  //输出链表
{
	if (!headNode) {
		return;
	}
	struct Node* p = headNode->next;
	while (p)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int choice;
	int data, index, position;
	printf("本通讯录系统有如下几个功能：\n");
	printf("1.创建通讯录链表;\n");
	printf("2.向通讯录中添加数据;\n");
	printf("3.删除通讯录中指定的数据;\n");
	printf("4.查找通讯录中指定数据;\n");
	printf("5.输出通讯录中所有数据;\n");
	printf("6.退出.\n");
	struct Node* headNode = NULL;
	while (1)
	{
		printf("请输入你的选择：");
		scanf("%d", &choice);
		if (choice == 1) {
			headNode = CreateList();
			printf("通讯录创建完毕！\n");
		}
		else if (choice == 2) {
			if (!headNode) {
				printf("通讯录未创建！\n");
			}
			else {
				printf("请输入你想要添加的数据和位置：");
				scanf("%d %d", &data, &index);
				if (index <= 0 || index > ListLength(headNode)) {
					printf("插入位置不合法！\n");
				}
				else {
					InsertNode(headNode, index, data);
					printf("数据添加完毕！\n");
				}
			}
		}
		else if (choice == 3) {
			if (!headNode) {
				printf("通讯录未创建或找不到删除的数据！\n");
			}
			else if (headNode->next == NULL) {
				printf("通讯录为空，请先添加数据！\n");
			}
			else {
				printf("请输入你想要删除的数据：");
				scanf("%d", &data);
				if (IndexOfNode(headNode, data) == -1) {
					printf("未找到删除的数据！\n");
				}
				else {
					DeleteNode(headNode, data);
					printf("数据删除完毕！\n");
				}
			}
		}
		else if (choice == 4) {
			if (!headNode || !headNode->next) {
				printf("通讯录链表未创建或找不到该结点数据！\n");
			}
			else {
				printf("请输入你想要查询的数据：");
				scanf("%d", &data);
				position = IndexOfNode(headNode, data);
				if (position == -1) {
					printf("未找到查询的数据！\n");
				}
				else {
					printf("你想要查询的数据的位置索引是：%d\n", position);
				}
			}
		}
		else if (choice == 5) {
			if (!headNode) {
				printf("通讯录链表未创建或链表为空！请先创建链表！\n");
			}
			else {
				printf("通讯录中所有的数据是：");
				PrintList(headNode);
			}
		}
		else if (choice == 6) {
			break;
		}
		else {
			printf("您输入的指令不合法，请重新输入!\n");
		}
	}
	return 0;
}