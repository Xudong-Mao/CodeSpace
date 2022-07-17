# include <stdio.h>
// 混合运算
int main(){
    int i = 5;
    float j = i / 2; // j 输出的是2还是2.5呢？2因为i的类型为整形计算出来的还是整型
    float k = (float)i / 2; // （float）i整体变成浮点数，最后结果为浮点数
    printf("j=%f\nk=%f\n",j,k); // j输出为2 ,k输出2.5
}