# include <stdio.h>
// 一个scanf读多种类型的数据
// 混合输入类型，每次在%c之前加一个空格
int main(){
    int i;
    char c;
    float f;
    scanf("%d %c%f",&i,&c,&f);
    printf("i=%d,c=%c,f=%f",i,c,f);
    // printf 控制输出
    printf("name=%c,age=%3d,socre=%5.2f","xiaoming",34,98.5); // 3 表示占三个位置 ， 5.2 表示总共显示5位小数点后两位
    return 0;
}