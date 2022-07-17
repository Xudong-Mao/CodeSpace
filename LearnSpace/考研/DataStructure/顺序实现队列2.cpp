// 队列致允熙在一段进行插入（入队），在另一端删除的（出队）线性表
// 特点：先进先出FIFO
// 顺序存储实现方案二
# include <stdint.h>
# define MaxSize 10
typedef ElemType;

typedef struct 
{
    ElemType data[MaxSize];   // 静态数组存放队列元素
    int font,rear;                  // 队头指针和队尾指针
    int size;                 // 队列当前长度
}SqQueue;

// 初始化队列
void InitQueue(SqQueue &Q){
    // 初始时，队头、队尾指针指向0
    Q.rear=Q.font=0;
    Q.size = 0;
}

// 判断是否为空队头和队尾指针相同
bool QueueEmpty(SqQueue Q){
    if(Q.size == 0){
        return true;
    }else{
        return false;
    }
}

// 入队只能从队尾入队
bool EnQueue(SqQueue &Q, ElemType x){
    if(Q.size == MaxSize){ 
        return false;
    } // 队满
    Q.data[Q.rear] = x; // 将x插入队尾
    Q.rear=(Q.rear+1)%MaxSize; // 队尾指针加一取模  改实现方式逻辑上是一个圆叫做循环队列
    Q.size++; 
    return true;
}

// 出队（删除一个队头元素并用x返回)

bool DeQueue(SqQueue &Q ,ElemType &x){
    if(Q.size == 0){ // 队为空
        return false;
    }
    x = Q.data[Q.font];
    Q.font=(Q.font+1)%MaxSize; // 队头指针后移
    Q.size--;
    return true;
}

// 获取队头元素的值，用x返回
bool GetQueue(SqQueue Q, ElemType &x){
    if(Q.size == 0){ // 队为空
        return false;
    }
    x=Q.data[Q.font];
    return true;
}

// 获取队列长度
int GetLenghtQueue(SqQueue &Q, ElemType &x){
    x=Q.size;
    return x;
} 

void testQueue(){
    SqQueue Q;  // 声明一个队列
    InitQueue(Q);
}