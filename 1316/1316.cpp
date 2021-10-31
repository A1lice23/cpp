#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){

    int N;
    char word[101] = {};
    bool alpha[26] = {};
    bool flag;
    int cnt = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        scanf("%s", word);
        flag = true;
        fill_n(alpha, 26, false);
        for(int j = 0; word[j] != '\0'; j++){
            if(alpha[word[j] - 'a']){
                if(word[j-1]==word[j])
                    continue;
                else
                    flag = false;
            }else{
                alpha[word[j]-'a'] = true;
            }
        }
        if(flag){
            //printf("%s\n", word);
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}