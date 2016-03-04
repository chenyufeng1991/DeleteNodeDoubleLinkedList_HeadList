//
//  main.c
//  DeleteNodeDoubleLinkedList_HeadList
//
//  Created by chenyufeng on 16/3/4.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

/**
 *  实现删除带头结点尾结点的双向非循环链表中的一个节点：
 （1）删除pos位置的节点；
 （2）查找x是否在链表中，若存在则删除之；
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef int elemType;
typedef struct NodeList{

    int element;
    struct NodeList *prior;
    struct NodeList *next;
}Node;

//初始化带头结点和尾结点的非循环双向链表
void InitialList(Node **pHead,Node **pTail){

    *pHead = (Node *)malloc(sizeof(Node));
    *pTail = (Node *)malloc(sizeof(Node));

    if (*pHead == NULL || *pTail == NULL) {
        printf("%s函数执行，内存分配失败，初始化双链表失败\n",__FUNCTION__);
    }else{
        //这个里面是关键，也是判空的重要条件
        (*pHead)->prior = NULL;
        (*pTail)->next = NULL;

        //链表为空的时候把头结点和尾结点连起来
        (*pHead)->next = *pTail;
        (*pTail)->prior = *pHead;

        printf("%s函数执行，带头结点和尾节点的双向非循环链表初始化成功\n",__FUNCTION__);
    }
}

//创建带头结点和尾结点的双向非循环链表
void CreateList(Node *pHead,Node *pTail){

    Node *pInsert;
    Node *pMove;
    pInsert = (Node*)malloc(sizeof(Node));
    memset(pInsert, 0, sizeof(Node));
    pInsert->prior = NULL;
    pInsert->next = NULL;

    scanf("%d",&(pInsert->element));
    pMove = pHead;
    while (pInsert->element > 0) {

        pMove->next = pInsert;
        pInsert->prior = pMove;
        pInsert->next = pTail;
        pTail->prior = pInsert;
        pMove = pInsert;

        pInsert = (Node *)malloc(sizeof(Node));
        memset(pInsert, 0, sizeof(Node));
        pInsert->prior = NULL;
        pInsert->next = NULL;

        scanf("%d",&(pInsert->element));
    }

    printf("%s函数执行完成，带头节点和尾结点的双向非循环链表创建成功\n",__FUNCTION__);

}

//正序打印链表
void PrintList(Node *pHead,Node *pTail){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        printf("%d ",pMove->element);
        pMove = pMove->next;
    }

    printf("\n%s函数执行，正序打印带头结点尾结点的双向非循环链表创建成功\n",__FUNCTION__);
}

//删除pos位置的节点
int DeletePosList(Node *pHead,Node *pTail,int pos){

    int i = 1;
    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (i == pos) {
            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除pos=%d位置的节点成功\n",__FUNCTION__,pos);
            return 1;
        }
        i++;
        pMove = pMove->next;
    }
    printf("%s函数执行，删除pos=%d位置的节点失败\n",__FUNCTION__,pos);
    return 0;
}

//删除值为x的节点，若存在该节点则删除之
int DeleteValueList(Node *pHead,Node *pTail,int x){

    Node *pMove;
    pMove = pHead->next;
    while (pMove != pTail) {
        if (pMove->element == x) {
            pMove->prior->next = pMove->next;
            pMove->next->prior = pMove->prior;
            free(pMove);
            pMove = NULL;
            printf("%s函数执行，删除值为x=%d的节点成功\n",__FUNCTION__,x);
            return 1;
        }
        pMove = pMove->next;
    }

    printf("%s函数执行，删除值为x的节点失败\n",__FUNCTION__);
    return 0;
}

int main(int argc, const char * argv[]) {

    Node *pHead;//头结点
    Node *pTail;//尾结点

    InitialList(&pHead, &pTail);

    CreateList(pHead, pTail);
    PrintList(pHead, pTail);

    DeletePosList(pHead, pTail, 2);
    PrintList(pHead, pTail);

    DeleteValueList(pHead, pTail, 5);
    PrintList(pHead, pTail);

    return 0;
}

