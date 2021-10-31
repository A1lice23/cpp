#include <stdio.h>

int main(){

    char temp[1000001] = {};
    int alpha[26] = {0};
    int max = -1;
    char ans;


    scanf("%s", temp);
    
    for(int i = 0; temp[i] != '\0'; i++){
        if(temp[i] >= 'a' && temp[i] <= 'z')
            alpha[temp[i]-'a']++;
        else
            alpha[temp[i]-'A']++;
    }
    for(int i = 0; i < 26; i++){
        if(alpha[i] == max){
            max = alpha[i];
            ans = '?';
        }else if(alpha[i] > max){
            max = alpha[i];
            ans = 'A' + i;
        }
    }
    printf("%c", ans);
    
    return 0;
}