#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dp[200002];
map<int, ll> M;

int main(){

    int n, k, x;
    ll total = 0;

    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        dp[i] = dp[i-1] + x;
    }
    for(int i = 1; i <= n; i++){
        if(dp[i] == k)
            total++;
        total += M[dp[i] - k];
        M[dp[i]]++;
    }
    printf("%lld", total);
    return 0;
}