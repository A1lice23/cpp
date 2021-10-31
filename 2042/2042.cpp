#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> a;
ll tree[4000001];

ll init(int start, int end, int node){
    if(start == end)
        return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node*2) + init(mid+1, end, node*2+1);
}

ll sum(int start, int end, int node, int l, int r){
    if(l > end || r < start)
        return 0;
    if( l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    return sum(start, mid, node*2, l, r) + sum(mid+1, end, node*2+1, l, r);
}

void update(int start, int end, int node, int index, ll diff){
    if(index < start || index > end)
        return;
    tree[node] += diff;
    if(start == end)
        return;
    int mid = (start + end) / 2;
    update(start, mid, node*2, index, diff);
    update(mid+1, end, node*2+1, index, diff);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    a.resize(1000001);

    int n, m, k;
    ll x, y, z;

    cin >> n >> m >> k;
    m += k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    init(0, n-1, 1);

    while(m--){
        cin >> x >> y >> z;
        if(x == 1){
            y--;
            ll diff = z - a[y];
            a[y] = z;
            update(0, n-1, 1, y, diff);
        }else if(x == 2){
            cout << sum(0, n-1, 1, y-1, z-1) << "\n";
        }
    }
    return 0;
}