#include <bits/stdc++.h>

using namespace std;

bool isVisited[100001] = {false};

int max_len = 0, max_node;

void dfs(vector<pair<int,int>> *t, int start, int len){
    if(isVisited[start])
        return;
    
    isVisited[start] = true;

    if(max_len < len){
        max_len = len;
        max_node = start;
    }
    for(auto it = t[start].begin(); it != t[start].end(); it++){
        dfs(t, (*it).first, (*it).second + len);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, x, y, node;
    cin >> v;

    vector<pair<int, int>> tree[v+1];
    for(int i = 1; i < v; i++){
        cin >> x >> y >> node;
        tree[x].push_back(make_pair(y, node));
        tree[y].push_back(make_pair(x, node));
    }

    dfs(tree, 1, 0);
    fill_n(isVisited, 100001, false);
    dfs(tree, max_node, 0);
    cout << max_len;

    return 0;
}