# include <stdio.h>

int main(){
    char *p = "hello";
    char c[10] = "hello";
    c[0] = 'H';
    // p[0] = 'H'; // 不可以对常量区数据进行修改
    printf("c[0]=%c\n",c[0]);
    printf("p[0]=%c\n",p[0]);
    p = "world"; //将字符串world的地址赋给p
    // c = "world" // 非法
    puts(p);
    return 0;
}