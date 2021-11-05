#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;
using ll = long long;

vector<ll> seq;
ll power_save[300001];

ll pow_2(ll n){
    ll res = 1;
    ll pow2 = 2;
    while(n){
        if(n & 1)
            res = res * pow2 % MOD;
        n >>= 1;
        pow2 = pow2 * pow2 % MOD;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    seq.resize(n);
    
    for(int i = 0; i < n; i++)
        cin >> seq[i];
    sort(seq.begin(), seq.end());

    for(int i = 0; i <= n; i++)
        power_save[i] = pow_2(i);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans += (seq[i] % MOD) * power_save[i] % MOD;
        ans -= (seq[i] % MOD) * power_save[n-i-1] % MOD;
        ans = ((ans%MOD)+MOD)%MOD;    
    }
    cout << ans;
    return 0;
}