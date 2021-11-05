#include <bits/stdc++.h>

using namespace std;
 
vector<pair<int, int>>g[20001];
int dis[20001];

void dijkstra(int start){
    dis[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    int cur, cost;
    while(!pq.empty()){
        cur = pq.top().second;
        cost = -pq.top().first;
        pq.pop();

        for(int i = 0; i < g[cur].size(); i++){
            int next = g[cur][i].first;
            int next_cost = cost + g[cur][i].second;

            if(dis[next] > next_cost){
                dis[next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int v, e, k;
    cin >> v >> e >> k;

    for(int i = 1; i <= v; i++)
        dis[i] = 1000000;

    int start, end, cost;

    for(int i = 0; i < e; i++){
        cin >> start >> end >> cost;
        g[start].push_back({end, cost});
    }

    dijkstra(k);

    for(int i = 1; i <= v; i++){
        if(dis[i] == 1000000)
            cout << "INF" << "\n";
        else
            cout << dis[i] << "\n";
    }

    
    return 0;
}
