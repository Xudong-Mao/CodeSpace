# include <stdio.h>
# include <stdlib.h>
// 单链表的尾插法和头插法

typedef int ElemType;

typedef struct LNode // 定义单链表节点类型
{
    ElemType data;   // 每个节点存放一个数据元素
    struct LNode *next; // 指针指向下一个节点
}LNode, *LinkList;

// 初始化一个空的单链表
bool InitList(LinkList &L){
    L = (LNode *) malloc(sizeof(LNode));
    if(L==NULL){ // 内存不足时分配失败
        return false;
    }
    L->next = NULL; // 头节点之后暂时还没有节点
    return true;
}

LinkList List_Tailinsert(LinkList &L){ // 正向建立单链表
    int x;                             // 设ElemType为整形
    L = (LinkList)malloc(sizeof(LNode)); // 建立头节点
    LNode *s, *r = L;                    // r为表尾指针
    scanf("%d",&x);                      // 输入结点的值
    while (x != 9999)                    // 输入9999表示结束                           
    {    // 在r结点之后插入元素X
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;                            // r指向新的额表尾结点,永远保证r指向最后一个结点
        scanf("%d",&x);                      
    }
    r->next=NULL;                       // 尾结点指针置空
    return L;
}

// 头插法: 考点用于链表的逆置
LinkList List_Headinsert(LinkList &L){
    LNode *s;
    int x;
    L=(LinkList)malloc(sizeof(LNode));  // 创建头结点
    L->next = NULL;        // 初始为空链表
    scanf("%d",&x);                      // 输入结点的值
    while (x != 9999)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s; // 将新结点插入表中，L为头指针
        scanf("%d",&x);                     
    }

    return L;
    
}

