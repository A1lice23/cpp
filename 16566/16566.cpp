#include <bits/stdc++.h>

using namespace std;

int root[4000001];
int card[4000001];

int find_rt(int x){
    if(x == root[x])
        return x;
    return root[x] = find_rt(root[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, k, x, selected, idx;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++)
        cin >> card[i];
    for(int i = 1; i <= m+1; i++)
        root[i] = i;
    sort(card+1, card+m+1);
    for(int i = 0; i < k; i++){
        cin >> x;
        idx = lower_bound(card+1, card+m+1, x) - card;
        /*
        cout << idx << "\n";
        for(int j = 1; j <= m; j++){
            cout << root[j] <<" ";
        }
        cout << "\n";
        */
        if(card[idx] == x){
            selected = find_rt(idx+1);
            cout << card[selected] << "\n";
            root[find_rt(selected)] = find_rt(selected + 1);
        }else{
            selected = find_rt(idx);
            cout << card[selected] << "\n";
            root[find_rt(selected)] = find_rt(selected + 1);
        }
    }
    return 0;
}