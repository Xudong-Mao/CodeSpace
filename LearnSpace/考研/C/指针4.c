#include <stdio.h>
#include <string.h>
#include <cstdlib>
// void 什么都不返回
// void* 无类型指针
// 指针与动态内存申请
// 数组一开始定义好就定义下来了，数组变量都在栈空间
// 程序是放在磁盘上的有序的指令集合，程序启动起来才叫进程
int main(){

    int i; // 申请多大的空间
    scanf("%d",&i);
    char *p;
    int *p1;
    p = (char*)malloc(i); // malloc申请空间单位是字节，返回的是viod*
    p1 = (int*)malloc(i);
    strcpy(p,"malloc success");
    puts(p);
    free(p); // 释放空间 p的值不会发生改变, p的值必须和malloc返回值一样
    free(p1);
    p = NULL; // 如果不把p值为null 成为野指针
    return 0;
}