#include <stdio.h>
#include <string.h>

int main(){

    char str[101] = {};
    bool flag;
    int cnt = 0;

    scanf("%s", str);

    for(int i = strlen(str)-1; i >= 0; i--){
        if(str[i]=='='){
            if(str[i-1]=='c' || str[i-1]=='s'){
                i--;
            }else if(str[i-1] == 'z'){
                i--;
                if(str[i-1] == 'd')
                    i--;
            }
        }else if(str[i]=='-'){
            if(str[i-1]=='c' || str[i-1]=='d'){
                i--;
            }
        }else if(str[i]=='j'){
            if(str[i-1]=='l' || str[i-1]=='n'){
                i--;
            }
        }
        cnt++;
    }
    printf("%d", cnt);
    return 0;
}