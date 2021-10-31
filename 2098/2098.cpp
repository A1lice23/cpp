#include <bits/stdc++.h>
#define MAX 999999999;

using namespace std;

int n;
int graph[17][17];
int cost[16][1<<16];

int TSP(int cur, int visited){
    int res;
    int ret = cost[cur][visited];
    if(ret != 0)
        return ret;
    
    if(visited==(1<<n)-1){
        if(graph[cur][0] != 0)
            return graph[cur][0];
        return MAX;
    }
    ret = MAX;
    for(int i = 0; i < n; i++){
        if(graph[cur][i] == 0 || (visited&(1<<i)))
            continue;
        ret = min(ret, graph[cur][i] + TSP(i, visited|1<<i));
    }
    cost[cur][visited] = ret;
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    cout << TSP(0,1);
    return 0;
}