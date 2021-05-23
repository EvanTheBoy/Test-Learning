#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Stack {
	struct Node* stacktop;   //ջ�����
	int stacksize;  //ջ��Ԫ�ظ���
};

struct Node* CreateNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Stack* CreateStack()  //�½�һ����ջ
{
	struct Stack* myStack = (struct Stack*)malloc(sizeof(struct Stack));
	myStack->stacktop = NULL;
	myStack->stacksize = 0;
	return myStack;
}

void push(struct Stack* myStack, int data)  //��ջ����
{
	struct Node* newNode = CreateNode(data);
	newNode->next = myStack->stacktop;  //����ʹ��ͷ�巨,��push��ջ��Ԫ��ָ��ԭ����ջ��Ԫ��
	myStack->stacktop = newNode;  //����ԭ����ջ��Ԫ�����ڲ���ջ����,����Ӧָ����push��ջ��newNode
	myStack->stacksize++;  //ͬʱջ�е�Ԫ�ظ�����1
}

int GetTop(struct Stack* myStack)   //�õ�ջ��Ԫ��
{
	if (myStack->stacksize == 0) {
		printf("ջΪ��,�޷���ȡ��");
		return;
	}
	return myStack->stacktop->data;
}

void pop(struct Stack* myStack)   //��ջ����
{
	if (myStack->stacksize == 0) {
		printf("ջΪ�գ��޷���ջ��");
		return;
	}
	struct Node* nextNode = myStack->stacktop->next;  //�Ȼ�ȡջ��Ԫ��ָ�����һ��Ԫ��
	free(myStack->stacktop);  //�ͷų�ջԪ��
	myStack->stacktop = nextNode;  //ջ��ָ��ָ���µ�ջ��Ԫ��
	myStack->stacksize--;  //ͬʱԪ�ظ�����1
}

int StackLength(struct Stack* myStack)  //��ȡջ�ĳ���
{
	int i = 0;
	struct Node* temp = myStack->stacktop;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return i;
}

void PrintStack(struct Stack* myStack)   //��ӡ����
{
	struct Node* temp = myStack->stacktop;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int isEmpty(struct Stack* myStack)  //�ж��Ƿ�Ϊ��
{
	if (myStack->stacksize == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void clear(struct Stack* myStack)
{
	while (myStack->stacksize != 0)
	{
		pop(myStack);
	}
}

int main()
{
	struct Stack* myStack = CreateStack();
	int i, data;
	while (1)
	{
		printf("1.��ջ���������ݣ�2.�õ�ջ��Ԫ�ص����ݣ�3.��ջ��Ԫ���׳���4.��ӡջ��Ԫ�ز���ȡ���ȣ�5.���ջ��6.�˳���");
		scanf("%d", &i);
		if (i == 1) {
			printf("����������Ҫ��������ݣ�");
			scanf("%d", &data);
			push(myStack, data);
		}
		else if (i == 2) {
			printf("ջ��Ԫ��Ϊ��%d\n", GetTop(myStack));
		}
		else if (i == 3) {
			pop(myStack);
			printf("ջ��Ԫ�س�ջ�ɹ���\n");
		}
		else if (i == 4) {
			printf("ջ��Ԫ��Ϊ��");
			PrintStack(myStack);
			printf("ջ�ĳ���Ϊ��%d\n", StackLength(myStack));
		}
		else if (i == 5) {
			clear(myStack);
		}
		else if (i == 6) {
			break;
		}
	}
	return 0;
}