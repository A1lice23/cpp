#include <bits/stdc++.h>

using namespace std;

long long int a, b, c;

long long int multidiv(long long int x, long long int y){
    if(y <= 1){
        return x % c;
    }
    if(y % 2 == 0){
        return multidiv((x*x)%c, y/2);
    }else{
        return (multidiv((x*x)%c, y/2) * x) % c;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b >> c;

    cout << multidiv(a, b);

    return 0;
}