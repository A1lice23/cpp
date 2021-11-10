#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int powsave[1001];
int first[1001][1001];
int cyclelength[1001][1001];
int dp[1001][1001];

int powMod(int a, int b, int c){
    ll res = 1;
    ll powN = a;
    while(b){
        if(b & 1)
            res = (res * powN) % c;
        b >>= 1;
        powN = (powN * powN) % c;
    }
    return res;
}

int powA(int a){
    int res = 1;
    int powN = a;
    while(a){
        if(a & 1)
            res = min(10000, res * powN);
        a >>= 1;
        powN = min(10000, powN * powN);
    }
    return res;
}

int pow_ans(int a, int b, int c){
    if(b == 0) return a % c;
    if(c == 1) return 0;
    if(dp[b][c] >= 0) return dp[b][c];

    int x = pow_ans(a, b-1, c);
    if(x == 0) return dp[b][c] = 0;

    int fzero = first[x][c];
    int clen = cyclelength[x][c];

    int res;
    if(powsave[b-1] <= fzero)
        res = powMod(x, powsave[b-1], c);
    else{
        int y = pow_ans(a, b-1, clen);
        y = ((y-fzero-1) % clen + clen) % clen + 1;
        res = powMod(x, fzero+y, c);
    }
    return dp[b][c] = res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int cyclecheck[1001];

    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            memset(cyclecheck, -1, sizeof(cyclecheck));
            int length = 0; 
            int x = 1;
            while(1){
                x = x * i % j;
                if(cyclecheck[x] >= 0){
                    first[i][j] = cyclecheck[x];
                    cyclelength[i][j] = length - cyclecheck[x];
                    break;
                }
                cyclecheck[x] = length++;
            }
        }
    }
        
    int n, a, b, c;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b >> c;

        powsave[0] = a;
        for(int j = 1; j <= 1000; j++)
            powsave[j] = powA(powsave[j-1]);

        memset(dp, -1, sizeof(dp));
        cout << "Case #" << i << ": " << pow_ans(a, b, c) << "\n";
    }
    
    return 0;
}