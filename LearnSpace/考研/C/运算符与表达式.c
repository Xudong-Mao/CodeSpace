//先乘除后加减，两个操作数的运算符（双目运算符）
# include <stdio.h>

int main(){
    int g;
    int a = 4+5*2 - 6/3 +10%4;
    printf("%d\n",a);
    scanf("%d",&a);
    printf("a=%d\n",a);//如果输入的是1234，怎么输出为4321
    while (a != 0) // 当a不等于0进入
     {
        printf("%d",a%10);
        a = a/10;
    }
    return 0;

}