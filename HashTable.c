#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 800
typedef struct node {  //储存对应于每一个头结点的结点的值和下一结点
	int key;
	struct Node* next;
}Node;

typedef struct hashTable {  //这个结构体用来储存头结点
	struct Node* headNode;
}HashTable;

void initHashTable(HashTable hash[], int len)  //每一个头结点指向都先设为空
{
	for (int i = 0; i < len; i++) {
		hash[i].headNode = NULL;
	}
}

void createHashTable(HashTable hash[], int len, int data)  //创建哈希表
{
	int index = data % len;  //计算存储的序号
	if (!hash[index].headNode) {  //如果这个地方头结点还没有值，那就先把它存在这里
		Node* p = (Node*)malloc(sizeof(Node));
		p->key = data;
		p->next = NULL;
		hash[index].headNode = p;
	}
	else {
		Node* p, * q;
		p = hash[index].headNode;
		q = (Node*)malloc(sizeof(Node));
		while (p->next != NULL)  //这个循环可以找到最后一个结点
		{
			p = p->next;
		}
		q->key = data;
		q->next = NULL;
		p->next = q;
	}
}

int searchHashTable(HashTable hash[], int len, int data)  //在哈希表中进行查找
{
	int index = data % len;
	Node* p = hash[index].headNode;
	for (int i = 1;; i++) {
		if (!p) {
			printf("未找到该元素！\n");
			break;
		}
		else if (p->key == data) {
			printf("%d数据的位置是%d.\n", data, i);
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
	printf("哈希表长：");
	scanf("%d", &len);
	printf("数据个数：");
	scanf("%d", &num);
	HashTable hash[N];
	initHashTable(hash, len);
	for (int i = 0; i < num; i++) {
		printf("数据：");
		scanf("%d", &data);
		createHashTable(hash, len, data);
	}
	printf("你要搜索的数据：");
	scanf("%d", &data);
	searchHashTable(hash, len, data);
	return 0;
}