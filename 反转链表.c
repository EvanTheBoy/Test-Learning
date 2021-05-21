#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Node* CreateList()  //��������
{
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	headNode->next = NULL;
	return headNode;
}

struct Node* CreateNode(int data)   //�������
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

int ListLength(struct Node* headNode)  //��ȡ������
{
	int len = 0;
	while (headNode)
	{
		headNode = headNode->next;
		len++;
	}
	return len;
}

void InsertNode(struct Node* headNode, int index, int data)  //��ָ��λ�ò���ڵ�
{
	if (!headNode || index <= 0 || index > ListLength(headNode)) {  //δ�ҵ�����-1
		return -1;
	}
	else if (index == 1) {   //�������ǵ�һ��λ�õĲ������
		struct Node* newNode = CreateNode(data);
		newNode->next = headNode->next;
		headNode->next = newNode;
	}
	else {
		struct Node* temp = headNode;
		for (int i = 0; i < index - 1; i++) {   //����tempָ��һֱ�ƶ�
			temp = temp->next;
		}
		struct Node* newNode = CreateNode(data);
		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void ReverseList(struct Node* headNode)  //��ת������
{
	struct Node* pCur, * prev, * pNext;  //��Ҫ��������ָ��
	if (headNode == NULL || headNode->next == NULL) {
		return headNode;
	}
	prev = NULL;  //��һ��ָ����ΪNULL
	pCur = headNode->next;  //pCurָ���һ�������ݵĽ�㣬Ϊ��ǰָ��
	pNext = headNode->next->next;  //pNextָ��ڶ��������ݵĽ��
	while (1)
	{
		pCur->next = prev;   //�ı䵱ǰָ��ָ������ݵ�ָ�򣬼�ָ���
		if (pNext == NULL) {
			break;
		}
		prev = pCur;  //prev��ǰ�ƶ�һλ
		pCur = pNext;  //pCur��ǰ�ƶ�һλ
		pNext = pNext->next;  //pNextҲ��ǰ�ƶ�һλ
	}
	headNode->next = pCur;  //�����Ҫ�ı�ͷ����ָ��
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
		printf("1.���������������ݣ�2.��ӡ����3.��ӡ��ת����4.�˳���");
		scanf("%d", &i);
		if (i == 1) {
			printf("����������Ҫ��ӵ�λ�ã�");
			scanf("%d", &pos);
			printf("����������Ҫ��ӵ����ݣ�");
			scanf("%d", &data);
			InsertNode(pl, pos, data);
		}
		else if (i == 2) {
			printf("����Ϊ��\n");
			PrintList(pl);
		}
		else if (i == 3) {
			printf("��ת�������Ϊ��\n");
			ReverseList(pl);
			PrintList(pl);
		}
		else if (i == 4) {
			break;
		}
	}
	return 0;
}