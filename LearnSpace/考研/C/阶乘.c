# include <stdio.h>

int main(){
    int i;
    int j = 1;
    scanf("%d",&i);
    while (i){
        j *= i;
        i--;
    }
    printf("%d",j);
}