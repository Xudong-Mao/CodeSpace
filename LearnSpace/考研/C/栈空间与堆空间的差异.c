# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <cstdlib>

char* print_stack(){
    char c[17] = "I am print_stack";
    puts(c); // 正常答应
    return c;
}

char* print_malloc(){
    char *p = (char*)malloc(30);
    strcpy(p,"I am print_malloc");
    puts(p);
    return p;
}

int main(){
    char *p;
    p = print_stack(); // 栈空间会随着函数的执行结束而释放
    // puts(p);// 打印不出来
    printf("----------\n");
    p = print_malloc(); // 堆空间不会随子函数的结束而释放，必须自己free
    puts(p);
    return 0;
}