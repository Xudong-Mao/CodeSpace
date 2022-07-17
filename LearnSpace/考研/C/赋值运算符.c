# include <stdio.h>
# include <stdlib.h>

// sizeof不是函数，是C的关键字
// 自增，自减
// 前加加按优先级正常运算先加后判断
int main()
{
    int i = -1;
    int j;
    // i++;// 代表的是i=i+1
    j = i++ > -1; // 遇见后加加,拆除两部j=i>-1;i++
    printf("i=%d, j=%d\n",i,j);
    printf("i的字节数=%d\n",sizeof(i));
    return 0;
}