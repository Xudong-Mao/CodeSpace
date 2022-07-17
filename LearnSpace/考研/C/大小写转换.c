# include <stdio.h>

// ascll 中 A(97) <- a(97-32=65)
int main(){
    char c = 'a'; // 现在是小写字母
    c -= 32;
    printf("%c\n",c); // 转换成大写

}