#include <stdio.h>
#include <stdlib.h>
# define InitSize 10 // 默认的最大长度

typedef struct
{
    int *data; //指示动态分配数组的指针
    int MaxSize; //顺序表的最大容量
    int length; //顺序表的当前长度
}SqList;

void InitList(SqList &L){
    // 使用malloc 函数申请一片连续的存储空间
    L.data=(int *)malloc(InitSize*sizeof(int));
    L.length=0;
    L.MaxSize=InitSize;
}

// 按位查找
int GetElem(SqList L, int i){
	return L.data[i-1];
}

// 按值查找
// 在顺序表L中查找第一个元素值等于e的元素，并返回其位序
int LocateElem(SqList &L, int e) {
	for (int i = 0; i < L.length; i++) {
		if (L.data[i] == e) { // 结构型变量不能够比较
			return i + 1; // 数组下标为i元素值等于e，返回其位序 i+1
		}
	}
	return 0;  // 退出循环，说明查找失败
}



// 顺序表的插入
bool ListInsert(SqList &L, int i, int e){
    // 判断i的范围是否有效
    if(i<1 || i>L.length+1)
        return false;
    // 当存储空间已经满时，不能插入
    if(L.length >= InitSize)
        return false;
    // 将第i个元素及之后的元素后移
    for(int j=L.length;j>=i;j--)
        L.data[j] = L.data[j-1];
        L.data[i-1]=e; // 在位置i放入e
        L.length++;  // 长度加一
        return true;
}
int main() {
	SqList L;
	int e;
	int c;
	InitList(L);
    for(int i = 1; i <= 10; i++) {
        if(ListInsert(L, i, 3 * i)) {
        }
    }
	printf("********\n");
	for(int i=0 ; i<L.length; i++){
		printf("%d\n",L.data[i]);
	}
	printf("要查哪个值？\n");
	scanf("%d", &e);
	if (LocateElem(L, e) != 0) {
		printf("要查的值在第%d位\n", LocateElem(L, e));
	}
	else {
		printf("没有要查的数\n");
	}
	printf("********\n");
	printf("要查哪个位的值？\n");
	scanf("%d", &c);
	if (GetElem(L, c) != 0) {
		printf("要查的第%d位的值为%d\n", c,GetElem(L, c));
	}
	else {
		printf("没有查到\n");
	}
	return 0;
}

