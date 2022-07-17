# include "func.h"
// Linux 编译 gcc main.c func.c -o main
// 函数的声明，定义与调用
// 递归调用
// 变量及函数的作用域
// 先编译func.c 变成 func.obj main,c 变成main.obj
// 链接错误就是函数名无法引用
int i = 10; // 全局变量 尽量不用
void print(int a){
    printf("print i=%d\n",i);
}

int main(){
    int a  = 10;
    a = printstar(a); // printstar()函数调用
    print_massage();
    printstar(a);
    int i = 5;
    print(i); // 输出为10因为上面只是在main定义了一个名为i的局部变量
    return 0;

}