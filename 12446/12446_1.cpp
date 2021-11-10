#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000;  
const long long INF = 10000;  
  
int head[MAX_N+1][MAX_N+1];  
int cycle[MAX_N+1][MAX_N+1];  
int dp[MAX_N+1][MAX_N+1];  
int val[MAX_N+1];  
  
void init() {  
    int used[MAX_N+1];  
    for (int i = 1; i <= MAX_N; i++) {  
        for (int j = 1; j <= MAX_N; j++) {  
            memset(used, -1, sizeof(used));  
            int p = 0;  
            int x = 1;  
            while (1) {  
                x = x * i % j;  
                if (used[x] >= 0) {  
                    head[i][j] = used[x];  
                    cycle[i][j] = p - used[x];  
                    break;  
                }  
                used[x] = p++;  
            }  
        }  
    }  
    cerr << "init() done!" << endl;  
}  
  
long long power(long long x, long long b, long long mod) {  
    long long ret = 1LL;  
  
    while (b > 0) {  
        if (b & 1)  
            ret = ret * x % mod;  
        x = x * x % mod;  
        b >>= 1;  
    }  
  
    return ret;  
}  
  
long long power(long long x, long long b) {  
    long long ret = 1LL;  
  
    while (b > 0) {  
        if (b & 1)  
            ret = min(INF, ret*x);  
        x = min(INF, x*x);  
        b >>= 1;  
    }  
  
    return ret;  
}  
  
int rec(int x, int b, int mod) {  
    if (!b) return x % mod;  
    if (mod == 1) return 0;  
    if (dp[b][mod] >= 0) return dp[b][mod];  
  
    int y = rec(x, b-1, mod);  
    if (!y)  
        return dp[b][mod] = 0;  
  
    int p = head[y][mod];  
    int q = cycle[y][mod];  
  
    int ret;  
    if (val[b-1] <= p)  
        ret = power(y, val[b-1], mod);  
    else {  
        int z = rec(x, b-1, q);  
        z = ((z - (p+1)) % q + q) % q + 1;  
        ret = power(y, p+z, mod);  
    }  
  
    return dp[b][mod] = ret;  
}  
  
void solve() {  
    int T;  
  
    cin >> T;  
    for (int i = 0; i < T; i++) {  
        cerr << "solving case " << i+1 << endl;  
        int A, B, C;  
        cin >> A >> B >> C;  
  
        val[0] = A;  
        for (int j = 1; j <= MAX_N; j++)  
            val[j] = power(val[j-1], val[j-1]);  
  
        memset(dp, -1, sizeof(dp));  
        int ret = rec(A, B, C);  
        cout << "Case #" << i+1 << ": " << ret << endl;  
    }  
}  

int main(){
    init();
    solve();

    return 0;
}