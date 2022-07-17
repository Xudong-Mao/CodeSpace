# include <stdio.h>
// scanf 循环读取

// 清空缓冲区 rewind(stdin),stdin是标准输入
// int main(){
//     int i;
//     while(rewind(stdin),(scanf("%d",&i) != EOF)) // while是实现循环，后面要有一个小括号
//     // 发生错误EOF (值为-1)
//     {
//         printf("i=%d\n",i);
//     }
//     return 0;
    
// }


// 小写字母改大写
int main(){
    char c;
    while (scanf("%c",&c) != EOF){
        if(c!='\n') // 判断，后面有一个小括号，小括号里面是一个表达式
        { 
            printf("%c", c -32);
        }else{
            printf("\n");
        }
    }
}