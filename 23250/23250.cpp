#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull k;

ull pow_2(ull x){
    ull powN = 2;
    ull ans = 1;
    while(x){
        if(x & 1)
            ans *= powN;
        x /= 2;
        powN *= powN;
    }
    return ans;
}

void hanoi(int n, ull cnt, int start, int blank, int end){
    if(n <= 1){
        cout << start << " " << end;
    }else{
        if(ull(pow_2(n-1)-1 + cnt) >= k){
            hanoi(n-1, cnt, start, end, blank);
        }else if(ull(pow_2(n-1) + cnt) == k){
            cout << start << " " << end;
        }else{
            hanoi(n-1, ull(cnt + pow_2(n-1)), blank, start, end);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n >> k;
    hanoi(n, 0, 1, 2, 3);

    return 0;
}