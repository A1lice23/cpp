#include <bits/stdc++.h>

using namespace std;

struct b_id{
    int end;
    int cost;
};


vector<b_id> bus[1001];
vector<int> route[1001];
int cost[1001];

void dijkstra(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    
    cost[start] = 0;

    while(!pq.empty()){
        int route_cost = -pq.top().first;
        int cur_node = pq.top().second;
        //cout << pq.top().second << "\n";
        pq.pop();

        if(cost[cur_node] < route_cost)
            continue;
        
        for(int i = 0; i < bus[cur_node].size(); i++){
            int dist = route_cost + bus[cur_node][i].cost;
            if(dist < cost[bus[cur_node][i].end]){
                cost[bus[cur_node][i].end] = dist;
                route[bus[cur_node][i].end].assign(route[cur_node].begin(), route[cur_node].end());
                route[bus[cur_node][i].end].push_back(bus[cur_node][i].end);
                pq.push({-dist, bus[cur_node][i].end});
            }
        }
    }
    
}

int main(){

    int n, m, srt, end, b_cost, t_start, t_end;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> srt >> end >> b_cost;
        bus[srt].push_back({end, b_cost});
    }
    cin >> t_start >> t_end;

    fill_n(cost, 1001, 1e9);

    dijkstra(t_start);
    
    cout << cost[t_end] <<"\n";
    cout << route[t_end].size()+1 << "\n";
    cout << t_start << " ";
    for(int i = 0; i < route[t_end].size(); i++)
        cout << route[t_end][i] << " ";

    return 0;
}