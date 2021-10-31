#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll tree[4000001];

ll mul(int start, int end, int node, int l, int r){
    if(l > end || r < start)
        return 1;
    if( l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    return (mul(start, mid, node*2, l, r) * mul(mid+1, end, node*2+1, l, r)) % 1000000007;
}

ll update(int start, int end, int node, int index, ll change){
    if(start > index || end < index)
        return tree[node];
    if(start == end)
        return tree[node] = change;
    int mid = (start + end) / 2;
    return  tree[node] = (update(start, mid, node*2, index, change) * (update(mid+1, end, node*2+1, index, change))) % 1000000007;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    ll x, y, z, val;

    cin >> n >> m >> k;
    m += k;
    for(int i = 1; i <= n; i++){
        cin >> val;
        update(1, n, 1, i, val);
    }

    while(m--){
        cin >> x >> y >> z;
        if(x == 1){
            update(1, n, 1, y, z);
        }else{
            cout << mul(1, n, 1, y, z) << "\n";
        }
    }
    return 0;
}