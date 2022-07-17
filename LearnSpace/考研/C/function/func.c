# include "func.h"
// printstar()函数定义，就是函数实现
int printstar(int i)  // i即为形式参数,形参
{
    printf("*****************\n");
    printf("printstar %d \n", i);
    return i +3;
}

void print_massage() // 可以调用printstar
{
    printf("how do you do\n");
    printstar(3);
}