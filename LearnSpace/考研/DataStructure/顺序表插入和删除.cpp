# include<stdio.h>
# define MaxSize 10

typedef struct 
{
    int data[MaxSize];
    int length;
}SqList;

void InitList(SqList &L){
    for(int i = 0; i<MaxSize; i ++){
        L.data[i] = 0; // 将所有数据元素设置设置为初始值
        L.length = 0; // 顺序表初始长度为0
    }
}

// 顺序表的插入
bool ListInsert(SqList &L, int i, int e){
    // 判断i的范围是否有效
    if(i<1 || i>L.length+1)
        return false;
    // 当存储空间已经满时，不能插入
    if(L.length >= MaxSize)
        return false;
    // 将第i个元素及之后的元素后移
    for(int j=L.length;j>=i;j--)
        L.data[j] = L.data[j-1];
        L.data[i-1]=e; // 在位置i放入e
        L.length++;  // 长度加一
        return true;
}

// 顺序表的删除

bool ListDelete(SqList &L, int i, int &e){
    // 判断i的范围是否有效
    if(i<1 || i>L.length)
        return false;

    e=L.data[i-1];   // 将删除的元素赋值给e
    for(int j=i;j<L.length;j++)
        L.data[j-1]=L.data[j];
    L.length--;      // 线性表长度减一
    return true;
}

int main(){
    SqList l;
    InitList(l);
    for (int i = 0; i<=MaxSize; i++){
        printf("插入前l[%d]=%d\n",i,l.data[i]);
    }
    // 往顺序表中随便插入几个元素
    for(int i = 1; i <= 10; i++) {
        if(ListInsert(l, i, 3 * i)) {
            // printf("插入成功\n");
        }
    }
    printf("***********\n");
    for (int i = 0; i<=MaxSize; i++){
        printf("插入后l[%d]=%d\n",i,l.data[i]);
    }

    int e = -1;
    if(ListDelete(l,3,e)){
        printf("已经删除第3个元素，删除的元素值为%d\n",e);
    }else{
        printf("位置i不合法，删除失败\n");
    }
    printf("***********\n");
    for (int i = 0; i<=MaxSize; i++){
        printf("删除后l[%d]=%d\n",i,l.data[i]);
    }

    return 0;
}
