# include <stdio.h>


void test(int x){
    x=1024;
    printf("test函数内部x = %d\n",x);
}
void test2(int &a){ // 改成引用类型参数就“带回来”了
    a=1024;
    printf("test函数内部x = %d\n",a);
}
int main(){
    int x = 1;
    printf("调用test前x = %d\n",x);
    test(x);
    printf("调用test后x = %d\n",x); // 输出为1对参数结果没有带回
    test2(x);
    printf("调用test2后x = %d\n",x);
}