# include <stdio.h>
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
int main(){
    LinkList L; // 声明一个指向单链表的指针
    InitList(L); // 初始化单单链表
    printf("该单链表为空吗？ %d\n",Empty(L));
    return 0;
}
