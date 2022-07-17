# include <stdio.h>

// 不用指针
// void change(int j){ // j 为形参
//     j=5;
// }
// int main(){
//     int i = 10; // i 是局部变量
//     printf("before change i =%d\n",i);  // 输出：before change i =10
//     change(i);// C语言函数调用是都是值传递，把i为实参
//     printf("after changed i =%d\n",i); // 输出： before change i =10
//     return 0;
// }

// 指针的传递
void change(int *j){ // j 为形参
    *j=5; // 指针的间接访问
}
int main(){
    int i = 10; // i 是局部变量
    printf("before change i =%d\n",i);
    change(&i);// C语言函数调用是都是值传递，把&i为实参
    printf("after changed i =%d\n",i); // 输出：after changed i =5
    return 0;
}


