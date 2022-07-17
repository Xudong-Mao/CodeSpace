# include <stdio.h>

void print(char c[]){
    int i = 0;
    while (c[i] != '\0')
    {
        printf("%c", c[i]);
        i ++;
    }
    printf("\n");
    // 首字母大写
    // c[0] = c[0] -32;
    
}

int main(){
    char c[10] = "hello";
    print(c);
}