# include <stdio.h>

// scanf 读取的是标准输入，printf 输出到控制台，标准输出
// scanf 原理：去标准缓冲区匹配ascall码但是注意回车的时候缓冲区会多一个\n不会
// 因为程序的向下执行而消失，例子如下例1
// scanf阻塞规则：在读取整型、浮点、字符串时会忽略缓冲区的'\n'空格符等字符，如例子2
// 缓冲区为空的时候，scanf才会阻塞
int main(){
    int i;
    char c;
    float j;
    //例1
    scanf("%d",&i);   //将标准输入转换成整型     
    printf("i=%d\n",i);
    // scanf("%c",&c);
    // printf("c=%c\n",c);
    //例2 使用前注释上两行
    scanf("%f",&j);
    printf("j=%f\n",j);

}