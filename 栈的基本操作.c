#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};

struct Stack {
	struct Node* stacktop;   //栈顶标记
	int stacksize;  //栈中元素个数
};

struct Node* CreateNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

struct Stack* CreateStack()  //新建一个空栈
{
	struct Stack* myStack = (struct Stack*)malloc(sizeof(struct Stack));
	myStack->stacktop = NULL;
	myStack->stacksize = 0;
	return myStack;
}

void push(struct Stack* myStack, int data)  //进栈函数
{
	struct Node* newNode = CreateNode(data);
	newNode->next = myStack->stacktop;  //这里使用头插法,新push进栈的元素指向原来的栈顶元素
	myStack->stacktop = newNode;  //由于原来的栈顶元素现在不是栈顶了,所以应指向新push进栈的newNode
	myStack->stacksize++;  //同时栈中的元素个数加1
}

int GetTop(struct Stack* myStack)   //得到栈顶元素
{
	if (myStack->stacksize == 0) {
		printf("栈为空,无法获取！");
		return;
	}
	return myStack->stacktop->data;
}

void pop(struct Stack* myStack)   //出栈函数
{
	if (myStack->stacksize == 0) {
		printf("栈为空，无法出栈！");
		return;
	}
	struct Node* nextNode = myStack->stacktop->next;  //先获取栈顶元素指向的下一个元素
	free(myStack->stacktop);  //释放出栈元素
	myStack->stacktop = nextNode;  //栈顶指针指向新的栈顶元素
	myStack->stacksize--;  //同时元素个数减1
}

int StackLength(struct Stack* myStack)  //获取栈的长度
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

void PrintStack(struct Stack* myStack)   //打印函数
{
	struct Node* temp = myStack->stacktop;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int isEmpty(struct Stack* myStack)  //判断是否为空
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
		printf("1.向栈中输入数据；2.得到栈顶元素的数据；3.将栈顶元素抛出；4.打印栈中元素并获取长度；5.清空栈；6.退出：");
		scanf("%d", &i);
		if (i == 1) {
			printf("请输入你想要输入的数据：");
			scanf("%d", &data);
			push(myStack, data);
		}
		else if (i == 2) {
			printf("栈顶元素为：%d\n", GetTop(myStack));
		}
		else if (i == 3) {
			pop(myStack);
			printf("栈顶元素出栈成功！\n");
		}
		else if (i == 4) {
			printf("栈中元素为：");
			PrintStack(myStack);
			printf("栈的长度为：%d\n", StackLength(myStack));
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