#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> graph[1001];
vector<pair<int, int>> rgraph[1001];
int dist[1001];
int total_dist[1001];

void dijkstra(vector<pair<int, int>> g[1001], int target, int size){
    
    int node, cost, n_node, n_cost;
    
    fill_n(dist, 1001, 10000000);
    dist[target] = 0;
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, target));
    while(!q.empty()){
        node = q.top().second;
        cost = -q.top().first;
        q.pop();
        if(dist[node] >= cost){
            for(int i = 0; i < g[node].size(); i++){
                n_node = g[node][i].first;
                n_cost = g[node][i].second + cost;
                if(dist[n_node] > n_cost){
                    dist[n_node] = n_cost;
                    q.push(make_pair(-n_cost, n_node));
                }
            }
        }
    }
    for(int i = 1; i <= size; i++)
        total_dist[i] += dist[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, s, e, cost, res = 0;

    cin >> n >> m >> x;
    while(m--){
        cin >> s >> e >> cost;
        graph[s].push_back(make_pair(e, cost));
        rgraph[e].push_back(make_pair(s, cost));
    }
    dijkstra(graph, x, n);
    dijkstra(rgraph, x, n);

    for(int i = 1; i <= n; i++){
        if(res < total_dist[i])
            res = total_dist[i];
    }
    cout << res << "\n";
    return 0;
}