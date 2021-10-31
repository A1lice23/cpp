#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull seq[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

ull modpow(ull a, ull b, ull x);
bool miller(ull a, ull x);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, cnt = 0;
    ull a;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        a = a * 2 + 1;
        for(int j = 0; j < 12; j++){
            if(miller(seq[j], a) == false){
                cnt++;
                break;
            }
        }
    }
    cout << n - cnt;
    return 0;
}

ull modpow(ull a, ull b, ull x){
    ull ans = 1;
    a %= x;
    while(b){
        if(b % 2)
            ans = (ans*a) % x;
        b /= 2;
        a = (a*a) % x;
    }
    return ans;
}

bool miller(ull a, ull x){
    if(a % x == 0)
        return true;
    ull k = x - 1;
    ull tmp;
    while(true){
        tmp = modpow(a, k, x);
        if(tmp == x - 1)
            return true;
        if(k % 2)
            return(tmp == 1 || tmp == x - 1);
        k /= 2;
    }
}