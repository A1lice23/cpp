#include <bits/stdc++.h>

using namespace std;

char s1[1001], s2[1001];
int lcs[1001][1001];

int main(){
    
    cin >> s1 >> s2;

    for(int i = 1; i <= strlen(s1); i++){
        for(int j = 1; j <= strlen(s2); j++){
            if(s1[i-1] == s2[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    cout << lcs[strlen(s1)][strlen(s2)];

    return 0;
}