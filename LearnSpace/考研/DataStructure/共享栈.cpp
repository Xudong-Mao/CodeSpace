// 共享栈
# define MaxSize 10
typedef ElemType;

typedef struct 
{
    ElemType data[MaxSize];   // 静态数组存放栈中元素
    int top0;                  // 0号栈顶指针(永远指向栈底)
    int top1;                  // 1号栈顶指针
}SqStack;

// 初始化栈
void InitStack(SqStack &S){
    S.top0=-1; // 初始化栈顶指针
    S.top1=MaxSize;
    // 当栈顶指针指向0的时候 进栈：S.data[S.top++]=x; 出栈: x=S.data[--S.top]; 栈满条件top == MaxSize
}

// 新元素进栈
bool Push(SqStack &S, ElemType x){
    if(S.top0 + 1 == S.top1){  // 栈满，报错
        return false;
    }    
    S.top0 = S.top0 + 1; // 指针先加一
    S.data[S.top0] = x; // 新元素入栈
    // 上两行等价于S.data[++S.top]=x;
    return true;
}

// 出栈操作(数据还残留在内存中，只是逻辑上被删除了)
bool Pop(SqStack &S, ElemType &x){
    if(S.top0==-1){// 栈空，报错
        return false;
    }
    x=S.data[S.top0]; // 栈顶元素先出栈
    S.top0 = S.top0 - 1; // 指针减1
    // 上两行等价于 x=S.data[S.top--];
    return true;
}

// 读取栈顶元素
bool GetTop(SqStack &S, ElemType &x){
    if(S.top0==-1){// 栈空，报错
        return false;
    }
    x=S.data[S.top0]; // x记录栈顶元素
    return true;
}


void testStack(){
    SqStack s;
    InitStack(s);
}