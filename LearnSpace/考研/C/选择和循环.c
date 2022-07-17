# include <stdio.h>

// 关系运算符与逻辑运算符优先级很重要
// if else 一定要加上大括号

// int main()
// {
//     int i;
//     while (scanf("%d",&i) != EOF){
//         if (i > 0){
//             printf("i is bigger than 0\n");
//         }else if (i == 0){
//             printf("i is 0\n");
//         }
//         else {
//             printf("i is not bigger than 0\n");
//         }
//     }

//     return 0;
// }


// for 循环
// 表达式 for(表达式1;表达式2;表达式3) 语句; 表达式之间必须有；
// int main(){
//     int i, total;
//     // for语句中只能有两个分号,for循环后面不能加分号;
//     for (i= 1,total =0;i <=100; i++){
//         total = total + i;
//     }
//     printf("total is %d\n",total);
// }

// continue 语句
// 从1加到100 奇数求和
// int main(){
//     int i, total;
//     for (i= 1,total =0;i <=100; i++){
//         if(i % 2==0)// 如果i是偶数
//         {
//             continue; // 提前结束本轮循环
//         }
//         total = total + i;
//     }
//     printf("total is %d\n",total);
// }


// break 语句 结束整个语句
int main(){
    int i, total;
    for (i= 1,total=0;i<=100; i++){
        if(total >2000)// 如果i大于2000
        {
            break; // 结束循环
        }
        total = total + i;
    }
    printf("total is %d, i=%d\n",total,i);
    return 0;
}