# include <stdio.h>

// 计算正整数n!
int factorial(int n){
    if( n==0 || n==1)
        return 1;
    else
        return n * factorial(n-1);
}
// 斐波拉数列
int Fib(int n){
    if(n==0){
        return 0;
    }else if(n==1){
        return 1;
    }else{
        return Fib(n-1) + Fib(n-2);
    }
}

int main(){
    int x = factorial(10);
    int y = Fib(4);
    printf("%d\n",x);
}