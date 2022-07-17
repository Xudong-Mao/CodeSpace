# include <stdio.h>
# include <stdlib.h>
// 指针与一位数组
//  数组传递时是弱化为指针
// 数组名作为实参传递给子函数式，是弱化为指针的
void change(char *d){
    *d = 'H';
}
int main(){
    
    char c[10] = "hello";
    change(c);
    printf("%s\n",c);
    return 0;
    
    
}