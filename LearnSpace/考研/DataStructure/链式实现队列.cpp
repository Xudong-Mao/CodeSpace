# include <stdint.h>
# include <stdlib.h>
typedef ElemType;

typedef struct LinkNode
{
    ElemType data;   // 数据域
    struct LinkNode *next;   // 指针域
}LinkNode;                   

typedef struct            // 链式队列
{
    LinkNode *font,*rear; // 队列的队头和队尾指针
}LinkQueue;

// 初始化队列（带头节点)
bool InitQueue(LinkQueue &Q){
    // 初始时font和rear都指向头结点
    Q.font=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
    Q.font->next = NULL;
}

// // 初始化队列（不带头节点)
// bool InitQueue(LinkQueue &Q){
//     // 初始时font和rear都指向NULL
//     Q.font=Q.rear=NULL;
// }

// 判断队列是否为空(带头结点)
bool IsEmpty(LinkQueue Q){
    if(Q.font == Q.rear){
        return true;
    }else{
        return false;
    }
}


// // 判断队列是否为空(不带头结点)
// bool IsEmpty(LinkQueue Q){
//     if(Q.font == NULL){
//         return true;
//     }else{
//         return false;
//     }
// }


// 新元素入队（带头节点）
void EnQueue(LinkQueue &Q, ElemType x){
    LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s;  // 新结点插入到rear之后
    Q.rear=s;    // 修改表尾指针
}

// // 新元素入队（不带头节点）
// void EnQueue(LinkQueue &Q, ElemType x){
//     LinkNode *s=(LinkNode*)malloc(sizeof(LinkNode));
//     s->data = x;
//     s->next = NULL;    
//     if(Q.font == NULL){ // 在空队列中插入第一个元素 需要特殊处理
//         Q.font = s;     // 修改队头队尾指针
//         Q.rear = s;
//     }else{
//         Q.rear->next = s; // 新结点插入到rear之后
//         Q.rear=s;    // 修改表尾指针       
//     }
// }


// 出队（带头节点）
bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.font == Q.rear){
        // 空队
        return false;
    }
    LinkNode *p = Q.font->next;
    x = p->data; // 用变量x返回队头元素
    Q.font->next = p->next; // 修改头节点的next指针
    if(Q.rear==p){          // 此次是最后一个结点出队
        Q.rear=Q.font; // 修改rear指针
    }free(p); // 释放结点空间
    return true;
}

// // 出队（不带头节点）
// bool DeQueue(LinkQueue &Q, ElemType &x){
//     if(Q.font == Q.rear){
//         // 空队
//         return false;
//     }
//     LinkNode *p = Q.font; //p指向此次出队的结点 
//     x = p->data; // 用变量x返回队头元素
//     Q.font = p->next; // 修改头节点的指针
//     if(Q.rear==p){      // 此次是最后一个结点出队
//         Q.font = NULL; // font指向null
//         Q.rear = NULL; // rear指向null
//     }free(p); // 释放结点空间
//     return true;
// }




void testLinkQueue(){
    LinkQueue Q;   // 声明一个队列
    InitQueue(Q);  // 初始化队列
}