#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll sum[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, x;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> x;
        sum[i] = x + sum[i-1];
    }
    int a, b;
    while(m--){
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }

    return 0;
}