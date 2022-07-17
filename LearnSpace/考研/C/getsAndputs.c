#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <string.h>

int main()
{
    char c[20]; // 字符数组的数组名里存的就是字符数组的起始地址,编译器给C存的值类型为字符指针
    fgets(c,sizeof(c),stdin); // 一次读取一行时使用
    // gets(c); // 需要在头文件添加#define _CRT_SECURE_NO_WARNINGS
    puts(c); // 等价于printf("%s\c",c)
    // // str 函数使用
    // char c[20] = "wangdao";
    // printf("数组c内字符串的长度=%d\n",strlen(c));
    // // 字符串复制
    // char d[20];
    // strcpy(d,c); //有const修饰代表可以放一个字符串常量
    // // printf("COPY后的字符串d=%s\n",d);
    // puts(d);
    // // 字符串比较
    // int ret = strcmp("how","hello");
    // printf("两个字符串比较后的结果=%d\n",ret); // 字符串比较的是对应位置的ASCII值
    // // 字符串拼接
    // strcat(c,d); // 拼接两个字符串，目标数组要能够容纳拼接后的字符串
    // puts(c);
    return 0;

}