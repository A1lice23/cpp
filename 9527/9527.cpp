#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum_one[55];

ll find_one(ll x){
    ll sum_res = 0;
    for(int i = 55; i >= 1; i--){
        if((x & (1LL << i)) != 0){
            sum_res += sum_one[i-1];
            sum_res += x - (1LL << i) + 1;
            x -= (1LL << i);
        }
    }
    if(x == 1){
        sum_res++;
    }
    return sum_res;
}

int main(){
    ll a, b;
    cin >> a >> b;

    sum_one[0] = 1;
    for(int i = 1; i <= 54; i++)
        sum_one[i] = sum_one[i-1] * 2 + (1LL << i);
    

    cout << find_one(b) - find_one(a-1);

    return 0;
}