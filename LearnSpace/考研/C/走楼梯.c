# include <stdio.h>

int f(int a){

    if(a==2)return 2;

    else if (a==1)return 1;

    else

    return f(a-1)+f(a-2);
}
int main()
{
    int n;
    scanf("%d",&n);
    int result = f(n);
    printf("%d\n",result);
    return 0;
}