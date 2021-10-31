#include <stdio.h>

int main(){

    char str[1000001] = {};
    int cnt = 0;
    char lastword;

    scanf("%[^\n]", str);

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' ')
            cnt++;
        lastword = str[i];
    }
    //printf("%c\n", lastword);
    if(str[0] == ' ')
        cnt--;
    if(lastword == ' ')
        cnt--;
    printf("%d", cnt+1);

    return 0;
}

