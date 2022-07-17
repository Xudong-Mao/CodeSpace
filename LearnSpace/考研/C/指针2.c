# include <stdio.h>
# include <stdlib.h>
// 指针与自增自减运算符（相对不难重要）

int main(){
    int a[3] = {2,7,8};
    int *p;
    int j,d;
    p = a; // 让指正变量p,指向数组的开头
    j = *p++;// j=*p;p++,任何时候都是把后加加去掉，然后看另外一个运算符优先级是否高于++
    // d = (*p)++; // d=*p;(*p)++,*p指向的是a的空间开头，自增后变为3，d指向*p为2 等价于 d=a[0]++
    printf("a[0]=%d,j=%d,*P=%d\n",a[0],j,*p); //227 需要注释d
    // printf("a[0]=%d,d=%d,*P=%d\n",a[0],d,*p); //323
    printf("----------\n");
    j = p[0]++; // j=p[0];p[0]++
    printf("a[0]=%d,j=%d,*P=%d\n",a[0],j,*p); // 278
    return 0;
}   
