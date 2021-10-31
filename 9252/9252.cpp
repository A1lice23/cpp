#include <bits/stdc++.h>

using namespace std;

int lcs[1001][1001];
char s1[1001], s2[1001];
char ans[1001];
int idx;

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
    int x = strlen(s1);
    int y = strlen(s2);
    while(lcs[x][y] != 0){
        if(lcs[x][y] == lcs[x][y-1]){
            y--;
        }else if(lcs[x][y] == lcs[x-1][y]){
            x--;
        }else{
            ans[idx++] = s1[x-1];
            x--; y--;
        }
    }
    idx--;
    cout << "\n";
    for(; idx >= 0; idx--){
        cout << ans[idx];
    }
    
    return 0;
}