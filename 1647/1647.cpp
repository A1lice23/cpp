#include <bits/stdc++.h>

using namespace std;

struct link{
    int start, end, cost;
};

vector<link> edge;
int parent[100001];

bool compare(link a, link b){
    return a.cost < b.cost;
}

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool unionfind(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)
        return true;
    else{
        parent[x] = y;
        return false;
    }
}

int main(){

    int n, m, last, sum = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        parent[i] = i;
        
    for(int i = 0; i < m; i++){
        link tmp;
        cin >> tmp.start >> tmp.end >> tmp.cost;
        edge.push_back(tmp);
    }

    sort(edge.begin(), edge.end(), compare);
    
    for(int i = 0; i < m; i++){
        if(!unionfind(edge[i].start, edge[i].end)){
            last = edge[i].cost;
            sum += last;
        }
    }

    cout << sum - last;

    return 0;
}

