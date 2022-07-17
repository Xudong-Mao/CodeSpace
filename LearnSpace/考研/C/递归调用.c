# include <stdio.h>

// 使用递归完成n!的计算
// 递归：就是函数自己调用自己
int f(int n)
{
    if(1==n){
        return 1; // 一定要写结束条件
    }
    return n * f(n-1) ; // 第一步写好公式
}

int main(){
    int n = 5;
    int result = f(n);
    printf("result=%d\n",result);
}