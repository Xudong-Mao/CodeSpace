# include <stdio.h>
# include <stdlib.h>
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

// 判断单链表是否为空
bool Empty(LinkList L){
    if(L->next==NULL){
        return true;
    }else{
        return false;
    }
}

// bool Empty(LinkList L){
//     return (L==NULL);
// }

// 在第i个位置插入元素e（带头节点）

bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1){            // 插入位置不满足条件
        return false;
    }

    LNode *p; // 指针p指向当前扫描到的结点
    int j=0;  // 当前p指向的是第几个结点
    p = L;    // L 指向头结点，头结点是第0个结点（不存放数据）
    while (p!=NULL && j<i-1) //循环找到第i-1个结点
    {
        p = p->next;
        j++;
    }

    // 实现后插操作后以下代码可以用后插函数替代
    if(p==NULL){ // i值不合法
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode)); // 申请插入结点空间
    s->data = e; // 插入e数据赋值给s
    // 以下两句不能更换顺序
    s->next = p->next; // s结点的指针指向p的下一个节点
    p->next = s; //将结点s连到p之后  
    return true;
    // return InsertNextNode(p,e);
}

// 前插操作：在结点p之前插入元素 e
bool InsertPriorNode(LNode *p, ElemType e){
    if (p = NULL){
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s==NULL){// 内存分配失败
        return false;
    } 
    s->next = p->next; // 将申请的s头结点指向p的头节点
    p->next = s; // p的下一个节点指向s, 新结点S连到P之后
    s->data = p->data; // 将p中元素复制到s中
    p->data = e; // p 中元素覆盖为e
    return true;
}

//后插入操作：在p结点之后插入元素e
bool InsertNextNode(LNode *p,ElemType e){
    if (p==NULL)
    {
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode)); // 申请插入结点空间
    if (s==NULL){
        return false; // 内存分配失败
    }
    s->data = e; // 插入e数据赋值给s
    s->next = p->next; // s结点的指针指向p的下一个节点
    p->next = s; //将结点s连到p之后  
    return true;   
}

// 按位删除结点
bool ListDelete(LinkList &L, int i ,ElemType &e){
    LNode *p; // 指针P指向当前扫描到的结点
    int j = 0; // 当前P指向的是第几个结点
    p = L; //L指向头结点，头结点是第0个结点（不存数据）
    while (p != NULL && j < i-1)
    { // 循环找到第i-1个结点
        p = p->next;
        j++;
    }
    if(p==NULL){
        return false; // i值不合法
    }
    if(p->next == NULL) {// 第i-1个结点之后已无其他结点
        return false;
    }
    LNode *q = p->next; // 令q指向被删除结点
    e = q->data; // 用e返回元素的值
    p->next = q->next; // 将*q结点从链中“断开”
    free(q); // 释放结点的存储空间
    return true; // 删除成功
    
}

// 删除指定结点p
bool DeleteNode(LNode *p){
    if (p == NULL){
        return false;
    }
    // 以下代码存在一定bug极限情况后面最后null会报空指针错误
    LNode *q = p->next; // 令q指向被删除结点
    p->data=p->next->data;// 和后继结点交换数据域
    p->next = q->next; // 将*q结点从链中“断开”
    free(q); // 释放结点的存储空间
    return true; // 删除成功
}

// 按位查找返回第i个元素
LNode * GetElem(LinkList L, int i){
    if(i<0){
        return NULL;
    }
    LNode *p; //指针P指向当前扫描到的结点
    int j = 0; // 当前p指向的是第几个结点
    p = L; // L指向头结点，头结点是第0个结点
    while (p !=NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}

// 按值查找，找到数据域==e的结点
LNode * LocateElem(LinkList L, ElemType e){
    LNode *p = L->next;
    // 从第一个结点开始查找数据域为e的结点
    while (p!= NULL && p->data != e)
    {
        p= p->next;
    }
    return p; //找到后返回该结点的指针，否则返回NULL
    
}

// 求表的长度
int Lenght(LinkList L){
    int len = 0; // 统计长度
    LNode *p = 0;
    while (p->next != NULL)
    {
        p = p->next;
        len++;
    }
    return len;
    
}


int main(){
    LinkList L; // 声明一个指向单链表的指针
    InitList(L); // 初始化单单链表
    printf("插入成功吗？%d\n",ListInsert(L,1,3));
    return 0;
}