#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
int col[16], diag1[32], diag2[32];

void search(int j){
    if (j == n){
        cnt++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(col[i] || diag1[i+j] || diag2[i-j+n-1]) continue;
        col[i] = diag1[i+j] = diag2[i-j+n-1] = 1;
        search(j+1);
        col[i] = diag1[i+j] = diag2[i-j+n-1] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    search(0);
    cout << cnt;

    return 0;
}