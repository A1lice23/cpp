#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll totient(ll n){
    ll phi = n;
    for(ll i = 2; i*i <= n; i++){
        if(n % i == 0){
            phi -= phi / i;

            while(n % i == 0)
                n /= i;
        }
    }
    if(n > 1)
        phi -= phi / n;
    return phi;
}


int main(){

    ll number;
    cin >> number;
    while(number != 0){
        cout << totient(number) << "\n";
        cin >> number;
    }
    return 0;
}