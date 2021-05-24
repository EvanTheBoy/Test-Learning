#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* CreateList() //��������ĺ���
{
    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    headNode->next = NULL;
    return headNode;
}

struct Node* CreateNode(int data)  //�����ڵ�
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

int GetData(struct Node* headNode, int data)  //���Һ���
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

void DeleteNodeInOneMinute(struct Node* headNode, struct Node* target)  //��O(1)��ʱ�临�Ӷ���ɾ�����
{
    if (headNode->next == NULL) {  //ֻ��һ���ڵ�
        return;
    }
    if (target->next == NULL) {  //Ҫɾ�������β���
        if (headNode->next == target) {  //ͷ�����һ����㼴β���
            headNode->next = NULL;
            free(target);
        }
        else {
            struct Node* pMove = headNode->next;  //����pMoveָ�벻����ǰ�ƶ�
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


void deleteNodeByPosition(struct Node* headNode, int num)  //ɾ��ĳ���ڵ�
{
    struct Node* posNodeFront = headNode;   //��ǰ�ڵ��ǰ��һ���ڵ���ͷ���
    struct Node* posNode = headNode->next;  // ��ǰ�ڵ��ͷ�����һ����ʼ
    if (posNode == NULL) {
        printf("����Ϊ�գ��޷�ɾ����\n");
    }
    else {
        while (posNode->data != num)  //���ѭ����������ָ�벻����ǰ�ƣ�ֱ���ҵ�num
        {
            posNodeFront = posNode;  //�������Ҫ�ҵĽڵ㣬���ƶ���ǰ�ڵ���ǰ��
            posNode = posNode->next;
            if (posNode == NULL)  //���һֱ�ұ�������û�ҵ��Ļ�
            {
                printf("δ�ҵ������Ϣ��\n");
                return;  //ֱ��ʹ��������
            }
        }
        posNodeFront->next = posNode->next;
        free(posNode);  //һ��Ҫ�ǵ��ͷű�ɾ���Ľڵ�
    }
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

void purge(struct Node* headNode)  //ȥ�غ���
{
    struct Node* p, * q, * succ, * cur;
    p = headNode->next;
    headNode->next = NULL;
    while (p != NULL)
    {
        succ = p->next;  // ���½��p�ĺ��
        q = headNode->next;  //qָ���±�ĵ�һ�����
        cur = headNode;  //����curָ������ȳ�ʼ��������ᱨ��
        while (q && p->data != q->data)  //����ʱ�����ӵ�һ����㿪ʼ���
        {
            cur = q;   //��¼��q��ǰһ�����
            q = q->next;  //����qָ�����
        }
        if (!q) {
            cur->next = p;
            p->next = NULL;
        }
        else {
            free(p);  //�ظ�����������һ��Ҫ�ǵ��ͷţ�
        }
        p = succ;
    }
}

void printList(struct Node* headNode)  //��ӡ����
{
    struct Node* pMove = headNode->next; //��ӡ����Ӧ�ô�ͷ�ڵ���һ����ʼ
    while (pMove != NULL)  //Ϊ�յĻ��϶��Ͳ��ܴ�ӡ
    {
        printf("%d ", pMove->data);
        pMove = pMove->next;
    }
    printf("\n");
}

int main(void)
{
    struct Node* List = CreateList();  //��������
    int i, data, pos;
    while (1)
    {
        printf("1.��ָ��λ�ô��������ݣ�2.����ĳ�����ݣ�3.ɾ��ĳ�����ݣ�4.��ӡ����5.����ȥ�أ�6.�˳������������ѡ��");
        scanf("%d", &i);
        if (i == 1) {
            printf("����������Ҫ��ӵ�λ�ã�");
            scanf("%d", &pos);
            printf("����������Ҫ��ӵ����ݣ�");
            scanf("%d", &data);
            InsertNode(List, pos, data);
        }
        else if (i == 2) {
            printf("����������Ҫ��ѯ�����ݣ�");
            scanf("%d", &data);
            pos = GetData(List, data);
            printf("����ҵ����ݵ�λ���ڣ�%d", pos);
            printf("\n");
        }
        else if (i == 3) {
            printf("����������Ҫɾ�������ݣ�");
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