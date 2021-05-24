#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* CreateList() //创建链表的函数
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

struct Node* CreateNode(int data)  //创建节点
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

int GetData(struct Node* headNode, int data)  //查找函数
{
    if (headNode == NULL) {
        return NULL;
    }
    struct Node* posNode = headNode->next;
    int j = 1;
    while (posNode)
    {
        if (posNode->data == data) {
            return j;
        }
        posNode = posNode->next;
        j++;
    }
    return -1;
}

void DeleteNodeInOneMinute(struct Node* headNode, struct Node* target)  //在O(1)的时间复杂度内删除结点
{
    if (headNode->next == NULL) {  //只有一个节点
        return;
    }
    if (target->next == NULL) {  //要删除结点是尾结点
        if (headNode->next == target) {  //头结点下一个结点即尾结点
            headNode->next = NULL;
            free(target);
        }
        else {
            struct Node* pMove = headNode->next;  //控制pMove指针不断向前移动
            while (pMove->next != target)
            {
                pMove = pMove->next;
            }
            pMove->next = NULL;
            free(target);
        }
        return;
    }
    struct Node* temp = target->next;
    target->data = temp->data;
    target->next = temp->next;
    free(temp);
}


void deleteNodeByPosition(struct Node* headNode, int num)  //删除某个节点
{
    struct Node* posNodeFront = headNode;   //当前节点的前面一个节点是头结点
    struct Node* posNode = headNode->next;  // 当前节点从头结点下一个开始
    if (posNode == NULL) {
        printf("链表为空，无法删除！\n");
    }
    else {
        while (posNode->data != num)  //这个循环用来控制指针不断往前移，直到找到num
        {
            posNodeFront = posNode;  //如果不是要找的节点，就推动当前节点往前走
            posNode = posNode->next;
            if (posNode == NULL)  //如果一直找遍了链表都没找到的话
            {
                printf("未找到相关信息！\n");
                return;  //直接使函数返回
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);  //一定要记得释放被删除的节点
    }
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

void purge(struct Node* headNode)  //去重函数
{
    struct Node* p, * q, * succ, * cur;
    p = headNode->next;
    headNode->next = NULL;
    while (p != NULL)
    {
        succ = p->next;  // 记下结点p的后继
        q = headNode->next;  //q指向新表的第一个结点
        cur = headNode;  //这里cur指针必须先初始化，否则会报错
        while (q && p->data != q->data)  //检查的时候必须从第一个结点开始检查
        {
            cur = q;   //记录下q的前一个结点
            q = q->next;  //控制q指针后移
        }
        if (!q) {
            cur->next = p;
            p->next = NULL;
        }
        else {
            free(p);  //重复结点就抛弃，一定要记得释放！
        }
        p = succ;
    }
}

void printList(struct Node* headNode)  //打印链表
{
    struct Node* pMove = headNode->next; //打印链表应该从头节点下一个开始
    while (pMove != NULL)  //为空的话肯定就不能打印
    {
        printf("%d ", pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}

int main(void)
{
    struct Node* List = CreateList();  //创建链表
    int i, data, pos;
    while (1)
    {
        printf("1.在指定位置处插入数据；2.查找某个数据；3.删除某个数据；4.打印链表；5.链表去重；6.退出；请输入你的选择：");
        scanf("%d", &i);
        if (i == 1) {
            printf("请输入你想要添加的位置：");
            scanf("%d", &pos);
            printf("请输入你想要添加的数据：");
            scanf("%d", &data);
            InsertNode(List, pos, data);
        }
        else if (i == 2) {
            printf("请输入你想要查询的数据：");
            scanf("%d", &data);
            pos = GetData(List, data);
            printf("你查找的数据的位置在：%d", pos);
            printf("\n");
        }
        else if (i == 3) {
            printf("请输入你想要删除的数据：");
            scanf("%d", &data);
            deleteNodeByPosition(List, data);
        }
        else if (i == 4) {
            printList(List);
        }
        else if (i == 5) {
            purge(List);
        }
        else if (i == 6) {
            break;
        }
    }
    return 0;
}