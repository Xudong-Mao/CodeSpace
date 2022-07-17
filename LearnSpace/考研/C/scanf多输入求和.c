# define PI 3 // 常量
# include <stdio.h>

// scanf函数：读取键盘的输入，标准输入
int main() {
    int a;
    int b;
    scanf("%d%d",&a,&b); // 一定要在变量前面加入&符号 读取两个整数
    printf("%d\n",a+b);

}