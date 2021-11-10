#include <bits/stdc++.h>

using namespace std;

int N, cnt = 0;
char s[120] = {};
int check[27] = {};

void getFont(int n, int bitmap){
    if(n == N){
        if(bitmap + 1 == (1 << 26))
            cnt++;
    }else{
        getFont(n+1, bitmap);
        getFont(n+1, bitmap | check[n]);
    }
}

int main(){
    
    cin >> N;
    for(int k = 0; k < N; k++){
        cin >> s;
        for(int i = 0; s[i] != '\0'; i++)
            check[k] = check[k] | (1 << (s[i] - 'a'));
    }
    getFont(0, 0);

    cout << cnt;

    return 0;
}