#include <stdio.h>

// 将数字反转看相等不
// 把最初输入的整型数a，反过来后再存到另一个整型数b，判断a和b是否相等
// int main()
// {
//     int i;
//     int j;
//     int sum = 0;
//     scanf("%d",&i);
//     int k = i;
//     while (k)
//     {
//         sum =sum*10+k%10; //sum =0,10,120,k=1,2,1
//         printf("%d",k%10);
//         k /= 10;
//     }
//     if (sum==i){
//         printf("yes");
//     }else{
//         printf("no");
//     }
//     return 0;
// }


// 答案
int main(){
    int a,b;
    while (scanf("%d",&a) != EOF)
    {
        
        while(a)
        {
            b = b *10 + a%10;
            a = a/ 10; 
        }
        if (a==b){
            printf("yes");
        }else
        {
            printf("no");
        }
    }
    
}