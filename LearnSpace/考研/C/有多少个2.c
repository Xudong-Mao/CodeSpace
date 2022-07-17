# include <stdio.h>

//整型数组读取5个整型数的方法如下：
int main(){
    int n;
    scanf("%d",&n);
    int a[100];
    int i,count= 0;
    for(i = 0;i < n; i++)
    { 
        scanf("%d",&a[i]); // 如何往数组里元素读入数据
    }
    for(i = 0;i < n; i++){
        if (a[i] == 2){
            count ++;
        }
    }
    printf("%d\n",count);
    return 0;
}
