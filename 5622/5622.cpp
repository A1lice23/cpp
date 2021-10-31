#include <stdio.h>

int check(char c){
    if(c >= 'Z'){
        c -= 2;
    }else if(c >= 'S'){
        c -= 1;
    }
    char num = c-'A';
    num /= 3;
    return num + 3;
}

int main(){

    char str[20] = {};
    int time = 0;

    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        time += check(str[i]);
    }

    printf("%d", time);

    return 0;
}