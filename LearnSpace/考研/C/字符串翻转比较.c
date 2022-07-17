# include <stdio.h>
# include <string.h>

int main(){
    char a[100];
    char b[100];
    fgets(a,sizeof(a),stdin); // 相比gets 多一个\n
    int len = strlen(a);
    a[len - 1] = '\0'; // 将最后的\n 替换成\0
    // gets(a);
    int i ,j;
    for(i = strlen(a) - 1,j = 0;i >= 0;i--,j++){
        b[j] = a[i];
    }
    b[j] = '\0';
    // puts(b);
    int result = strcmp(a,b);

    if (result < 0)

    {

    printf("%d\n",-1);

    }

    else if (result > 0)

    {

    printf("%d\n", 1);

    }

    else {

    printf("%d\n", 0);

    }
    return 0;
}