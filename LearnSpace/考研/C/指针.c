# include <stdio.h>

// 指针的使用场景---传递和偏移
// 指针的本质:用来保存地址,使用的本质：间接访问
// 二级指针的传递
// 指针四个字节

int main(){
    int i = 5;
    int *i_pointer= &i;//&符号:取地址，指针变量的初始化一定是某个变量取地址
    printf("i = %d\n",i); //直接访问
    printf("*p = %d\n",*i_pointer); //间接访问
    return 0;

}