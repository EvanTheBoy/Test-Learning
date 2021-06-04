#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 800
typedef struct node {  //�����Ӧ��ÿһ��ͷ���Ľ���ֵ����һ���
	int key;
	struct Node* next;
}Node;

typedef struct hashTable {  //����ṹ����������ͷ���
	struct Node* headNode;
}HashTable;

void initHashTable(HashTable hash[], int len)  //ÿһ��ͷ���ָ������Ϊ��
{
	for (int i = 0; i < len; i++) {
		hash[i].headNode = NULL;
	}
}

void createHashTable(HashTable hash[], int len, int data)  //������ϣ��
{
	int index = data % len;  //����洢�����
	if (!hash[index].headNode) {  //�������ط�ͷ��㻹û��ֵ���Ǿ��Ȱ�����������
		Node* p = (Node*)malloc(sizeof(Node));
		p->key = data;
		p->next = NULL;
		hash[index].headNode = p;
	}
	else {
		Node* p, * q;
		p = hash[index].headNode;
		q = (Node*)malloc(sizeof(Node));
		while (p->next != NULL)  //���ѭ�������ҵ����һ�����
		{
			p = p->next;
		}
		q->key = data;
		q->next = NULL;
		p->next = q;
	}
}

int searchHashTable(HashTable hash[], int len, int data)  //�ڹ�ϣ���н��в���
{
	int index = data % len;
	Node* p = hash[index].headNode;
	for (int i = 1;; i++) {
		if (!p) {
			printf("δ�ҵ���Ԫ�أ�\n");
			break;
		}
		else if (p->key == data) {
			printf("%d���ݵ�λ����%d.\n", data, i);
			break;
		}
		else {
			p = p->next;
		}
	}
}

int main()
{
	int len, data, num;
	printf("��ϣ����");
	scanf("%d", &len);
	printf("���ݸ�����");
	scanf("%d", &num);
	HashTable hash[N];
	initHashTable(hash, len);
	for (int i = 0; i < num; i++) {
		printf("���ݣ�");
		scanf("%d", &data);
		createHashTable(hash, len, data);
	}
	printf("��Ҫ���������ݣ�");
	scanf("%d", &data);
	searchHashTable(hash, len, data);
	return 0;
}