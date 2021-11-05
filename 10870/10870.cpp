#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll fibo(int n){
    if(n == 0)
        return 0;
    else if(n <= 2)
        return 1;
    else
        return fibo(n-1) + fibo(n-2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    cout << fibo(k);

    return 0;
}