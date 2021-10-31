#include <bits/stdc++.h>

using namespace std;

char s[2510];
int pel2[2510][2510];
int pel[2510];

int main(){
    cin >> s+1;
    //cout << s +1 << "\n";
    int n = strlen(s+1)+1;

    for(int i = 1; i <= n; i++)
        pel2[i][i] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i+1])
            pel2[i][i+1] = 1;
    }
    for(int i = 2; i < n; i++){
        for(int j = 1; j <= n-i; j++){
            if(s[j] == s[i+j] && pel2[j+1][j+i-1])
                pel2[j][j+i] = 1;
        }
    }

    for(int i = 1; i < n; i++){
        pel[i] = 10000;
        for(int j = 1; j <= i; j++){
            if(pel2[j][i])
                pel[i] = min(pel[i], pel[j-1] + 1);
        }
    }
    cout << pel[n-1];
    return 0;
}