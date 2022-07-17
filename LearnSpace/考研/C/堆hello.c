# include <stdio.h>
#include <cstdlib>

int main(){
    int i;
    char c;
    char *p;
    scanf("%d",&i);
    p = (char*)malloc(i);
    scanf("%c",&c);//注意在scanf和gets中间使用scanf("%c",&c),去除换行
    fgets(p,sizeof(p),stdin);
    puts(p);
}