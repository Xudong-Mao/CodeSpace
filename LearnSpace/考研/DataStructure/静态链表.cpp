// 静态链表：分配一整片连续的内存空间，各个结点集中安置，游标充当指针，-1表示达到表尾
// 静态链表：用数组方式实现的链表
# include <stdio.h>
# define MaxSize 10  // 静态链表最大长度
typedef ElemType;
typedef struct       // 静态链表结构类型定义
{
    ElemType data;   // 存储数据元素
    int next;        // 下一个元素的数组下标
}SLinkList[MaxSize];

// 初始化
// 增删插