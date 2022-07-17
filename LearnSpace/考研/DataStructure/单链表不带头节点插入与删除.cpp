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
    L = NULL; // 空表，暂时没有任何节点
    return true;
}

// 判断单链表是否为空
bool Empty(LinkList L){
    if(L==NULL){
        return true;
    }else{
        return false;
    }
}

// bool Empty(LinkList L){
//     return (L==NULL);
// }

// 在第i个位置插入元素e（带头节点）
// 由于不存在“第0个”结点，所以i=1时需要特殊的处理
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1){            // 插入位置不满足条件
        return false;
    }
    if(i==1){ // 插入第一个结点的操作与其他结点的操作不同
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L=s;         // 头指针指向新结点
        return true;

    }

    LNode *p; // 指针p指向当前扫描到的结点
    int j=1;  // 当前p指向的是第几个结点
    p = L;    // L 指向头结点，头结点是第0个结点（不存放数据）
    while (p!=NULL && j<i-1) //循环找到第i-1个结点
    {
        p = p->next;
        j++;
    }
    // 实现后插操作后以下代码可以用后插函数替代
    // return InsertNextNode(p,e);
    if(p==NULL){ // i值不合法
        return false;
    }
    LNode *s = (LNode *) malloc(sizeof(LNode)); // 申请插入结点空间
    s->data = e; // 插入e数据赋值给s
    // 以下两句不能更换顺序
    s->next = p->next; // s结点的指针指向p的下一个节点
    p->next = s; //将结点s连到p之后  
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

int main(){
    LinkList L; // 声明一个指向单链表的指针
    InitList(L); // 初始化单单链表
    printf("插入成功吗？%d\n",ListInsert(L,1,3));
    return 0;
}
