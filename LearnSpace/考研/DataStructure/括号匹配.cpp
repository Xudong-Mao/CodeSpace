// 栈的方式解决：遇到左括号就入栈，遇到有括号就“消耗”一个左括号
# include <stdio.h>
# define MaxSize 10
typedef ElemType;

typedef struct 
{
    char data[MaxSize];   // 静态数组存放栈中元素
    int top;    // 栈顶指针
}SqStack;

// 初始化栈
void InitStack(SqStack &S){
    S.top=0; // 初始化栈顶指针
    // 当栈顶指针指向0的时候 进栈：S.data[S.top++]=x; 出栈: x=S.data[--S.top]; 栈满条件top == MaxSize
}

// 新元素进栈
bool Push(SqStack &S, ElemType x){
    if(S.top == MaxSize){  // 栈满，报错
        return false;
    }    
    S.top = S.top + 1; // 指针先加一
    S.data[S.top++] = x; // 新元素入栈
    // 上两行等价于S.data[++S.top]=x;
    return true;
}

// 出栈操作(数据还残留在内存中，只是逻辑上被删除了)
bool Pop(SqStack &S, ElemType &x){
    if(S.top==-1){// 栈空，报错
        return false;
    }
    x=S.data[--S.top]; // 栈顶元素先出栈
    S.top = S.top - 1; // 指针减1
    // 上两行等价于 x=S.data[S.top--];
    return true;
}

// 判空
bool StackEmpty(SqStack S){
        if(S.top==-1){// 栈空，报错
        return false;
    }
}

// 括号匹配
bool bracketCheck(char str[], int length){
    SqStack S;
    InitStack(S);
    for (int i=0; i<length; i++){
        if (str[i]=='(' || str[i]=='[' || str[i]=='{'){
            Push(S, str[i]); // 扫描到左括号，入栈
        }else{
            if(StackEmpty(S))  // 扫描到右括号，且当前栈空
                return false;      // 匹配失败

            char topElem;
            Pop(S, topElem);   // 栈顶元素出栈
            if(str[i] == ')' && topElem != ')')
                return false;
            if(str[i] == ']' && topElem != '[')
                return false;
            if(str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S); // 检查完全部括号后，栈空说明匹配成功
}
