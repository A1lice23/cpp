#include <stdio.h>

int main(){

    char temp[101] = {};
    int T, R;

    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d %s", &R, temp);
        for(int j = 0; temp[j] != '\0'; j++){
            for(int k=0; k < R; k++)
                printf("%c", temp[j]);
        }
        printf("\n");
    }
    return 0;
}