#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> bus[1001];
int minCost[1001];

void dijkstra(int start){
    minCost[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({start, 0});
    while(!pq.empty()){
        int cur = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();

        if(minCost[cur] < dis)
            continue;
        for(int i = 0; i < bus[cur].size(); i++){
            int next = bus[cur][i].first;
            int nextCost = dis + bus[cur][i].second;
            if(nextCost < minCost[next]){
                minCost[next] = nextCost;
                pq.push({next, -nextCost});
            }
        }
    }
}

int main(){
    int n, m, first, last, cost;
    cin >> n >> m;

    fill_n(minCost, n+1, 2000000000);
    while(m--){
        cin >> first >> last >> cost;
        bus[first].push_back({last, cost});
    }
    int st, end;
    cin >> st >> end;
    dijkstra(st);

    cout << minCost[end];

    return 0;
}