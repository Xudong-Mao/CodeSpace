# include <stdio.h>
# include <stdlib.h>

typedef int ElemType;
typedef struct DNode               // 定义双链表结点类型
{
    ElemType data;                 // 数据域
    struct DNode *prior ,*next;   // 前驱和后继指针
}DNode, *DLinklist;


// 初始化双链表
bool InitDLinkList(DLinklist &L){
    L = (DNode *) malloc(sizeof(DNode));// 分配一个头结点
    if(L==NULL){
        return false;
    }
    // 循环双链表
    // L->next = L;
    // L->next = L;       // 循环双链表
    L->prior = NULL;      // 头结点的prior永远指向NULL
    L->next = NULL;       // 头结点之后暂时没有节点
    return true;
}

// 判断双链表是否为空
bool Empty(DLinklist L){
    if(L->next == NULL){ // 循环链表时条件为L->next==L
        return true;
    }else{
        return false;
    }
}

// 双链表的插入在p后插入s
bool InsertNextDNode(DNode *p, DNode *s){
    if(p == NULL || s == NULL){
        return false;
    }
    s->next = p->next;   // 将结点s插入到结点p之后
    if(p->next != NULL){ // 如果p节点有后继结点
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}


// 双链表的删除p结点的后继结点
bool DeleteNextDNode(DNode *p){
    if(p == NULL){
        return false; 
    }
    DNode *q = p->next; // 找到p的后继结点q
    if(q == NULL){
        return false;   // p没有后继
    }
    p->next = q->next; 
    if (q->next != NULL)  // q结点不是最后一个结点
        q->next->prior = p;
    free(q);              // 释放结点空间
    return true;
}

// 销毁双链表
void DestoryList(DLinklist &L){
    // 循环释放各个数据结点
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L); // 释放头节点
    L=NULL; // 头指针指向NULL
    
}


// 双链表的遍历


void testDLinkList(){
    // 初始化双链表
    DLinklist L;
    InitDLinkList(L);
} 