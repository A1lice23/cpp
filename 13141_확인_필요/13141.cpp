#include <bits/stdc++.h>
#define INF 1000000000

using namespace std;

int n, m, x, y, cost;
int adj[201][201] = {};
int dist[201][201] = {};

double getShortestTime(){
    double short_time = INF, long_time, spend_time, remain_len;
    int vertex_len;
    
    for(int i = 1; i <= n; i++){
        long_time = 0;
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                vertex_len = adj[j][k];

                if(vertex_len){
                    remain_len = vertex_len - (dist[i][k] - dist[i][j]);

                    if(remain_len > 0){
                        spend_time = (remain_len/2) + dist[i][k];
                        long_time = max(spend_time, long_time);
                    }
                }
            }
        }
        short_time = min(long_time, short_time);
    }
    return short_time;
}

int main(){

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }

    for(int i = 0; i < m; i++){
        cin >> x >> y >> cost;
        if(adj[x][y] < cost){
            adj[x][y] = cost;
            adj[y][x] = cost;
        }
        if(dist[x][y] > cost){
            dist[x][y] = cost;
            dist[y][x] = cost;
        }
    }

    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    cout << fixed;
    cout.precision(1);
    cout << getShortestTime();

    return 0;
}