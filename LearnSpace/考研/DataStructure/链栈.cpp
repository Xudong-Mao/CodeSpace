// 链栈将链头的一段看做栈顶，只能操作栈顶端
# include <stdint.h>
typedef ElemType;

typedef struct Linknode
{
    ElemType data;   // 数据域
    struct Linknode *next;   // 指针域
}*LStack;                    // 栈类型定义

//TODO 对于后续增删改的实现