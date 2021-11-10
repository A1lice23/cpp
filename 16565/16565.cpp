#include <bits/stdc++.h>
#define MOD 10007

using namespace std;

int C[53][53];


int main(){

    int n;
    cin >> n;
    for(int i = 0; i <= 52; i++){
        C[i][0] = 1; C[i][i] = 1;
        for(int j = 1; j < i; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
            C[i][j] %= MOD;
        }
    }
    int ans = 0, sign = 1;
    for(int i = 4; i <= n; i += 4){
        ans += sign * C[13][i/4] * C[52-i][n-i];
        ans %= MOD;
        sign *= -1;
    }
    if(ans < 0)
        ans += MOD;

    cout << ans;
    
    return 0;
}