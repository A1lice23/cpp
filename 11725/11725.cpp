#include <bits/stdc++.h>

using namespace std;

int parent[100002];
vector<int> tree[100002];
bool visited[100002];

void getParnet(int node){
    visited[node] = true;

    for(int i = 0; i < tree[node].size(); i++){
        int con = tree[node][i];

        if(!visited[con]){
            parent[con] = node;
            getParnet(con);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, x, y;
    cin >> n;
    for(int i = 1; i <= n; i++)
        parent[i] = i;

    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    getParnet(1);

    for(int i = 2; i <= n; i++)
        cout << parent[i] << "\n";


    return 0;
}