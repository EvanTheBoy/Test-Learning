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

void InsertNode(struct Node* headNode, int position, int data)  //��ͨѶ¼�в�������
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

void DeleteNode(struct Node* headNode, int data)  //ɾ��ĳ�����
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

int IndexOfNode(struct Node* headNode, int data)  //��ѯ
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
		if (pMove == NULL) {  //û���ҵ���ѯ�����ݾ���indexֱ��Ϊ-1�����������ж�
			index = -1;
			break;  //Ȼ��ǵ�����Ҫ�˳�ѭ��������������ȡ����Ȩ�޳�ͻ
		}
	}
	return index;
}

void PrintList(struct Node* headNode)  //�������
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
	printf("��ͨѶ¼ϵͳ�����¼������ܣ�\n");
	printf("1.����ͨѶ¼����;\n");
	printf("2.��ͨѶ¼���������;\n");
	printf("3.ɾ��ͨѶ¼��ָ��������;\n");
	printf("4.����ͨѶ¼��ָ������;\n");
	printf("5.���ͨѶ¼����������;\n");
	printf("6.�˳�.\n");
	struct Node* headNode = NULL;
	while (1)
	{
		printf("���������ѡ��");
		scanf("%d", &choice);
		if (choice == 1) {
			headNode = CreateList();
			printf("ͨѶ¼������ϣ�\n");
		}
		else if (choice == 2) {
			if (!headNode) {
				printf("ͨѶ¼δ������\n");
			}
			else {
				printf("����������Ҫ��ӵ����ݺ�λ�ã�");
				scanf("%d %d", &data, &index);
				if (index <= 0 || index > ListLength(headNode)) {
					printf("����λ�ò��Ϸ���\n");
				}
				else {
					InsertNode(headNode, index, data);
					printf("���������ϣ�\n");
				}
			}
		}
		else if (choice == 3) {
			if (!headNode) {
				printf("ͨѶ¼δ�������Ҳ���ɾ�������ݣ�\n");
			}
			else if (headNode->next == NULL) {
				printf("ͨѶ¼Ϊ�գ�����������ݣ�\n");
			}
			else {
				printf("����������Ҫɾ�������ݣ�");
				scanf("%d", &data);
				if (IndexOfNode(headNode, data) == -1) {
					printf("δ�ҵ�ɾ�������ݣ�\n");
				}
				else {
					DeleteNode(headNode, data);
					printf("����ɾ����ϣ�\n");
				}
			}
		}
		else if (choice == 4) {
			if (!headNode || !headNode->next) {
				printf("ͨѶ¼����δ�������Ҳ����ý�����ݣ�\n");
			}
			else {
				printf("����������Ҫ��ѯ�����ݣ�");
				scanf("%d", &data);
				position = IndexOfNode(headNode, data);
				if (position == -1) {
					printf("δ�ҵ���ѯ�����ݣ�\n");
				}
				else {
					printf("����Ҫ��ѯ�����ݵ�λ�������ǣ�%d\n", position);
				}
			}
		}
		else if (choice == 5) {
			if (!headNode) {
				printf("ͨѶ¼����δ����������Ϊ�գ����ȴ�������\n");
			}
			else {
				printf("ͨѶ¼�����е������ǣ�");
				PrintList(headNode);
			}
		}
		else if (choice == 6) {
			break;
		}
		else {
			printf("�������ָ��Ϸ�������������!\n");
		}
	}
	return 0;
}